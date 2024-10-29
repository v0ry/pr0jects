#include "udp.h"
#include "test_parser.h"
#include "test_shared.h"
#include "../quib.h"

#include <algorithm>
#include <vector>
#include <random>
#include <set>
#include <deque>
#include <cstring>

namespace std {
template <typename T> std::string to_string(std::optional<T> const& v) {
    if (v) return __CONTest::concatenate("Optional(value = ", std::to_string(*v), ")");
    else return "Optional(empty)";
}
std::string to_string(quib_status s) { return __CONTest::concatenate(uint32_t(s), " ([",quib_status_str(s), "])"); }
template <typename U, typename V> std::string to_string(std::pair<U,V> const& v) {
    return __CONTest::concatenate("(",std::to_string(v.first),", ",std::to_string(v.second),")");
}
template <typename T> std::string to_string(std::set<T> const& v) {
    if (v.empty()) return "{ <empty set> }";
    std::stringstream ss;
    ss << "{ ";
    bool first = true;
    for (auto const& e: v) {
        if (first) first = false; else ss << ", ";
        ss << std::to_string(e);
    }
    ss << " }";
    return ss.str();
}
}

namespace __CONTest { struct TestHarness; }
struct udp_socket {
    __CONTest::TestHarness* harness = nullptr;
};

namespace __CONTest {

#ifdef FRAMEWORK_DEBUG
const bool isFrameworkDebug = true;
#else
const bool isFrameworkDebug = false;
#endif

std::vector<std::string> ContextHandle::_activeContexts;

enum : uint8_t { FRAME_ENCODING_ERROR = 0x07, STREAM_STATE_ERROR = 0x05, FINAL_SIZE_ERROR = 0x06, PROTOCOL_VIOLATION = 0x0a };

struct Skip {};

static bool isTicking = false;
inline void tick(uint8_t n = 1) {
    static uint32_t x=0;
    if (n > 1) { frameworkDebug("== ticking %u times ==\n", n); };
    isTicking = true;
    for (uint8_t i=0; i<n; ++i) {
        frameworkDebug("--- start of tick %u ---\n", x++);
        quib_tick();
        frameworkDebug("--- end of tick ---\n");
    }
    isTicking = false;
}

void ensure_timeout() {
    frameworkDebug("reached end of test case, ensure_timeout() called...\n");
    for (uint8_t i=0; i<20; ++i) tick();
}

struct StreamHandle {
    StreamHandle(quib_stream* s) : _p(s, ::quib_discard_stream) {}
    std::unique_ptr<quib_stream, void(*)(quib_stream*)> _p;
    operator quib_stream*() { auto* p = _p.get(); assertThat("If this fails, it's a framework bug.", p != nullptr); return p; }
    void discard() { if (_p) _p.reset(nullptr); }
};

struct TestHarness;
struct TestHarness {
    static std::vector<TestHarness*> live;
    struct {
        ip_address address = Random::bytes<4>();
        udp_port port = udp_port(Random::number());
    } const peer;
    TestHarness() {
        live.push_back(this);
        assertSuccess(quib_connect(&connection, peer.address, peer.port));
        assertThat("the pointer has been initialized", connection != nullptr);
        assertThat("you have opened a udp socket", !this->sockets.empty());
        frameworkDebug("TestHarness() %p\n", this);
    }
    TestHarness(TestHarness&&) = delete;
    TestHarness(TestHarness const&) = delete;
    TestHarness& operator=(TestHarness const&) = delete;

    void discard() {
        if (!connection) return;
        quib_discard_connection(connection);
        connection = nullptr;
    }
    ~TestHarness() {
        frameworkDebug("~TestHarness() %p\n", this);
        discard();
        for (udp_socket* socket : sockets) socket->harness = nullptr;
        std::erase(live, this);
    }

    quib_connection* connection = nullptr;
    std::set<udp_socket*> sockets;

    StreamHandle newStream(bool bidir) {
        quib_stream* sHandle;
        assertSuccess(quib_new_stream(connection, &sHandle, bidir));
        return StreamHandle(sHandle);
    }

    StreamHandle acceptStream() {
        quib_stream* sHandle;
        assertSuccess(quib_accept_stream(connection, &sHandle));
        assertThat("The stream was available to accept", sHandle != nullptr);
        return StreamHandle(sHandle);
    }

    std::deque<std::vector<uint8_t>> serverToClientQueue;
    void sendToClient(QUIBPacket const& packet) {
        serverToClientQueue.push_back(encodeQUIBPacket(packet));
    }
    void sendToClient(std::vector<std::unique_ptr<QUIBPacket>> const& vec) {
        for (auto const& p : vec) sendToClient(*p);
    }

    std::deque<std::vector<uint8_t>> clientToServerQueue;
    std::vector<QUIBPacket> receiveFromClient() {
        auto packets = std::vector<QUIBPacket>();
        packets.reserve(clientToServerQueue.size());
        QUIBPacket(* const fnPtr)(std::vector<uint8_t> const&) = parseQUIBPacket;
        std::transform(clientToServerQueue.cbegin(), clientToServerQueue.cend(), std::back_inserter(packets), fnPtr);
        clientToServerQueue.clear();
        return packets;
    }

    void forwardTo(std::unique_ptr<QUIBServer> const& it) {
        auto packets = receiveFromClient();
        for (auto const& packet: packets) it->receivePacket(packet);
    }

    void forwardFrom(std::unique_ptr<QUIBServer> const& it) {
        for (auto const& packet : it->sendPackets())
            sendToClient(*packet);
    }

    void normalTick(std::unique_ptr<QUIBServer> const& it) {
        forwardFrom(it);
        tick();
        forwardTo(it);
    }

    operator quib_connection*() {
        assertThat("If this fails, it's a framework bug. (It never should.)", !!connection);
        return connection;
    }
    operator quib_connection const*() const {
        assertThat("If this fails, it's a framework bug. (It never should.)", !!connection);
        return connection;
    }
};
/*static*/ std::vector<TestHarness*> TestHarness::live;

template <typename C, typename Pred> inline bool forall(C const& c, Pred  pred) {
    return std::all_of(std::begin(c), std::end(c), pred);
}

template <typename C, typename Pred> inline bool forany(C const& c, Pred pred) {
    return std::any_of(std::begin(c), std::end(c), pred);
}

template <typename C, typename Fun> inline void foreach(C const& c, Fun fn) {
    std::for_each(std::begin(c), std::end(c), fn);
}

using ::quib_send_data;
inline static auto quib_send_data(quib_stream* s, char const* d, size_t sz, bool f) { return quib_send_data(s, reinterpret_cast<uint8_t const*>(d), sz, f); }

std::unique_ptr<QUIBServer> startServer(std::vector<QUIBPacket> const& packets) {
    assertThat("You sent an initial packet", !packets.empty());
    assertThat("You only sent a single initial packet", packets.size() == 1);
    return startServer(packets.front());
}

std::pair<std::unique_ptr<TestHarness>, std::unique_ptr<QUIBServer>> startServer() {
    auto h = std::make_unique<TestHarness>();
    tick();
    auto s = startServer(h->receiveFromClient());
    frameworkDebug("harness/server init complete\n");
    h->normalTick(s);
    return std::pair(std::move(h),std::move(s));
}

// TEST DEFINITIONS

constexpr std::pair<char const*, void(*)()> TESTS[] = {
    { "udp_socket", []() {
        TestHarness harness;
    }},
    { "open_close", []() {
        TestHarness harness;
        tick();
        auto packets = harness.receiveFromClient();
        assertThat("You sent an initial packet", !packets.empty());
        assertEquals("You only sent a single initial packet", packets.size(), 1u);
        auto const& initialPacket = packets.front();
        assertThat("The initial packet's packet number is zero", initialPacket.packetNumber == 0);
        
        auto server = startServer(initialPacket);
        harness.forwardFrom(server);
        tick();
        assertThat("You report the connection as opened", quib_is_connected(harness));
        quib_close_connection(harness);
        assertThat("You report the connection as closed", !quib_is_connected(harness));
        tick();
        harness.forwardTo(server);
        assertThat("You closed the connection", server->isClosed());
        ensure_timeout();
    }},
    { "ack_eliciting", []() {
        TestHarness harness;
        tick();
        auto packets = harness.receiveFromClient();
        assertEquals("You sent a single initial packet", packets.size(), 1u);
        auto server = startServer(packets.front());
        uint8_t successes = 0;
        for (uint8_t safeguard = 0; safeguard < 101; ++safeguard) {
            auto serverPackets = server->sendPackets();
            for (auto const& packet: serverPackets) harness.sendToClient(*packet);
            tick();
            if (server->getUnacknowledgedAckElicitingPacketNumbers().empty())
            {
                auto clientPackets = harness.receiveFromClient();
                assertThat("You should delay acknowledgements of ACK-only packets until you have non-ACK frames to send.",
                  !forany(clientPackets, [](auto const& packet) {
                    return forall(packet.payload, [](auto const& p) { return (dynamic_cast<ACKFrame const*>(p.get()) != nullptr); }); }));
                if (++successes > 5) break;
                for (auto const& packet: clientPackets) server->receivePacket(packet);
            } else harness.forwardTo(server);
            assertThat("You seem to be sending non-ACK frames on every tick. This prevents the connection from ever being idle.", safeguard < 100);
        }
    }},
    { "flow_control_outgoing", []() {
        auto [harness, server] = startServer();
        auto sHandle = harness->newStream(false);
        static uint8_t buf[5242880];
        for (size_t i=0; i<5242880; ++i) buf[i] = uint8_t(i);
        assertSuccess(quib_send_data(sHandle, buf, 5242880, true));
        harness->normalTick(server);
        auto stream = server->assertStream();
        assertThat("You did not exceed the implied flow control limit (1 MB)", stream->isReceivedExactlyUpTo(1048576));
        assertThat("You did not prematurely set the final bit", !stream->isReceiveComplete());

        stream->setMaxAllowedReceiveOffset(3145728);
        harness->normalTick(server);
        assertThat("You did not exceed the explicitly-specified flow control limit (3 MB)", stream->isReceivedExactlyUpTo(3145728));
        assertThat("You did not prematurely set the final bit", !stream->isReceiveComplete());

        stream->setMaxAllowedReceiveOffset(5242880);
        harness->normalTick(server);
        assertThat("You properly sent the data once flow control permitted it", stream->isReceivedExactlyUpTo(5242880));
        assertThat("You correctly set the final bit", stream->isReceiveComplete());
    }},
    { "flow_control_incoming", []() {
        auto [harness, server] = startServer();
        auto stream = server->newStream(false);
        std::vector<uint8_t> data = Random::bytes(10 * 1024 * 1024);
        stream->sendData(data);
        stream->markSendComplete();
        harness->normalTick(server);
        
        auto sHandle = harness->acceptStream();
        std::vector<uint8_t> data2; data2.resize(data.size());
        uint8_t* ptr = data2.data();
        size_t szR = data2.size();
        bool isFinal = false;
        for (uint8_t safeguard = 0; safeguard < 101 && !isFinal && szR; ++safeguard) {
            size_t nRead;
            assertSuccess(quib_receive_data(sHandle, ptr, szR, &nRead, &isFinal));
            ptr += nRead;
            szR -= nRead;
            harness->normalTick(server);
            assertThat("Infinite loop protection - are you sure you are advancing the flow control window?", safeguard < 100);
        }
        assertThat("You received all the data", isFinal);
        assertThat("The received data is correct", data == data2);
    }},
    { "packet_size_bait", []() {
        auto [harness, server] = startServer();
        auto sHandle = harness->newStream(false);
        std::vector<uint8_t> data = Random::bytes(5 * 1024 * 1024);
        assertSuccess(quib_send_data(sHandle, data.data(), 1, false));
        harness->normalTick(server);
        auto stream = server->assertStream();
        stream->setMaxAllowedReceiveOffset(20 * 1024 * 1024); // this is bait, because the maximum packet size is 3mb!
        harness->normalTick(server);
        assertSuccess(quib_send_data(sHandle, data.data()+1, data.size()-1, true));
        for (uint8_t i=0; !stream->isReceiveComplete() && i<25; ++i) harness->normalTick(server);
        assertThat("Data was transferred successfully", stream->isReceiveComplete() && stream->isReceivedExactlyUpTo(data.size()) && stream->getReceivedData() == data);
    }},
    { "packet_size_bait_multiple", []() {
        auto [harness, server] = startServer();
        auto sHandle1 = harness->newStream(false);
        auto sHandle2 = harness->newStream(false);
        std::vector<uint8_t> data1 = Random::bytes(5 * 1024 * 1024);
        std::vector<uint8_t> data2 = Random::bytes(4 * 1024 * 1024);
        assertSuccess(quib_send_data(sHandle1, data1.data(), 1, false));
        assertSuccess(quib_send_data(sHandle2, data2.data(), 2, false));
        harness->normalTick(server);
        assertEquals("You opened both streams", server->streams().size(), 2u);
        
        auto stream1 = server->streams().front();
        auto stream2 = server->streams().back();
        if (stream1->isReceivedExactlyUpTo(2)) { std::swap(stream1, stream2); }

        stream1->setMaxAllowedReceiveOffset(10 * 1024 * 1024);
        stream2->setMaxAllowedReceiveOffset(10 * 1024 * 1024);
        assertSuccess(quib_send_data(sHandle1, data1.data()+1, data1.size()-1, true));
        assertSuccess(quib_send_data(sHandle2, data2.data()+2, data2.size()-2, true));
        frameworkDebug("Now going to send data");
        for (uint8_t i=0; !(stream1->isReceiveComplete() && stream2->isReceiveComplete()) && i < 25; ++i) harness->normalTick(server);
        assertThat("Data was transferred successfully", stream1->isReceiveComplete() && stream1->isReceivedExactlyUpTo(data1.size()) && stream1->getReceivedData() == data1);
        assertThat("Data was transferred successfully", stream2->isReceiveComplete() && stream2->isReceivedExactlyUpTo(data2.size()) && stream2->getReceivedData() == data2);
    }},
    { "no_head_of_line_blocking", []() {
        auto [harness, server] = startServer();
        auto stream1 = server->newStream(false);
        auto data1 = Random::bytes(2048);
        auto data2 = Random::bytes(3097);
        stream1->sendData(data1.data(), 1);
        harness->normalTick(server);

        auto sHandle1 = harness->acceptStream();
        std::vector<uint8_t> recv1; recv1.resize(data1.size());
        std::vector<uint8_t> recv2; recv2.resize(data2.size());
        uint8_t* buf1 = recv1.data(); size_t buf1Sz = recv1.size();
        uint8_t* buf2 = recv2.data(); size_t buf2Sz = recv2.size();
        size_t szRead; bool isFinal;

        assertSuccess(quib_receive_data(sHandle1, buf1, buf1Sz, &szRead, &isFinal));
        assertThat("Not marked as final", !isFinal);
        assertEquals("Read size is correct", szRead, 1u);
        buf1 += szRead; buf1Sz -= szRead;

        auto stream2 = server->newStream(true);
        stream2->sendData(data2);
        harness->normalTick(server);

        auto sHandle2 = harness->acceptStream();
        assertSuccess(quib_receive_data(sHandle2, buf2, buf2Sz, &szRead, &isFinal));
        assertThat("Not marked as final", !isFinal);
        assertEquals("Read size is correct", szRead, data2.size());

        assertSuccess(quib_receive_data(sHandle1, buf1, buf1Sz, &szRead, &isFinal));
        assertThat("Not marked as final", !isFinal);
        assertEquals("Read size is correct", szRead, 0u);

        stream1->sendData(data1.data()+1, data1.size()-1);
        stream1->markSendComplete();
        stream2->markSendComplete();
        harness->normalTick(server);

        assertSuccess(quib_receive_data(sHandle2, buf2, buf2Sz, &szRead, &isFinal));
        assertThat("Marked as final", isFinal);
        assertEquals("Read size is correct", szRead, 0u);

        assertSuccess(quib_receive_data(sHandle1, buf1, buf1Sz, &szRead, &isFinal));
        assertThat("Marked as final", isFinal);
        assertEquals("Read size is correct", szRead, data1.size()-1);

        assertThat("Received data is correct", data1 == recv1);
        assertThat("Received data is correct", data2 == recv2);
    }},
    { "eos_no_data_send", []() {
        auto [harness, server] = startServer();
        auto sHandle = harness->newStream(false);
        auto data = Random::bytes(64);
        quib_send_data(sHandle, data.data(), data.size(), false);
        harness->normalTick(server);

        auto stream = server->assertStream();
        assertThat("Data was transmitted", stream->isReceivedExactlyUpTo(64));
        assertThat("Data was not finalized", !stream->isReceiveComplete());
        quib_send_data(sHandle, static_cast<uint8_t const*>(nullptr), 0, true);
        harness->normalTick(server);
        assertThat("No additional data was transmitted", stream->isReceivedExactlyUpTo(64));
        assertThat("Data is now finalized", stream->isReceiveComplete());
        assertThat("Data was transmitted correctly", stream->getReceivedData() == data);
    }},
    { "eos_no_data_recv", []() {
        auto [harness, server] = startServer();
        auto stream = server->newStream(false);
        auto data = Random::bytes(64);
        auto recv = std::vector<uint8_t>(); recv.resize(65);
        stream->sendData(data);
        harness->normalTick(server);

        auto sHandle = harness->acceptStream();
        size_t n; bool final;
        assertSuccess(quib_receive_data(sHandle, recv.data(), 65, &n, &final));
        assertEquals("Data was transmitted", n, 64u);
        assertThat("Data was not finalized", !final);
        stream->markSendComplete();
        harness->normalTick(server);
        assertSuccess(quib_receive_data(sHandle, recv.data()+64, 1, &n, &final));
        assertEquals("No additional data was transmitted", n, 0u);
        assertThat("Data is now finalized", final);
        recv.resize(64);
        assertThat("Data was transmitted correctly", recv == data);
    }},
    { "initial_nack", []() {
        TestHarness harness;
        tick();
        auto packets = harness.receiveFromClient();
        assertEquals("You sent a single initial packet", packets.size(), 1u);
        auto const& initialPacket = packets.front();
        assertThat("The initial packet's packet number is zero", initialPacket.packetNumber == 0);
        assertThat("You aren't pretending you've connected", !quib_is_connected(harness));
        
        tick(2); // now you should assume that the initial packet was lost, and try again
        auto packets2 = harness.receiveFromClient();
        assertEquals("You sent a single initial packet", packets2.size(), 1u);
        auto const& initialPacket2 = packets2.front();
        assertThat("The second initial packet's packet number is not the same", initialPacket2.packetNumber > initialPacket.packetNumber);
        assertThat("You aren't pretending you've connected", !quib_is_connected(harness));

        auto sHandle = harness.newStream(false);
        assertSuccess(quib_send_data(sHandle, "12345", 5, true));
        tick(2); // now you should assume that the second packet was also lost
        auto packets3 = harness.receiveFromClient();
        assertEquals("You sent a single initial packet", packets3.size(), 1u);
        auto const& initialPacket3 = packets3.front();
        assertThat("The third initial packet's packet number is not the same", initialPacket3.packetNumber > initialPacket2.packetNumber);
        assertThat("You aren't pretending you've connected", !quib_is_connected(harness));

        auto sHandle2 = harness.newStream(true);
        tick(2); // at this point, the connection should time out

        quib_stream* sHandleF;
        assertEquals("The connection should have timed out", quib_new_stream(harness, &sHandleF, false), ERR_CONNECTION_TIMEOUT);
        assertEquals("The connection should have timed out", quib_send_data(sHandle2, "1", 1, false), ERR_CONNECTION_TIMEOUT);

        auto server = startServer(initialPacket3);
        assertThat("Your re-sent initial packet also contained the available stream data",
            (server->streams().size() == 1) && (server->streams().front()->isRangeReceived(0,5)) && !memcmp(server->streams().front()->getReceivedData().data(), "12345", 5));
        harness.forwardFrom(server);
        tick();
        assertEquals("You should not have revived the connection", quib_new_stream(harness, &sHandleF, false), ERR_CONNECTION_TIMEOUT);
        assertEquals("You should not have revived the connection", quib_send_data(sHandle2, "1", 1, false), ERR_CONNECTION_TIMEOUT);
        assertThat("You aren't pretending you've connected", !quib_is_connected(harness));
    }},
    { "timeout_keepalive", []() {
        auto [harness, server] = startServer();
        for (size_t i=0; i<100; ++i) harness->normalTick(server);
        assertThat("The connection did not time out", quib_is_connected(*harness));
    }},
    { "initial_data", []() {
        TestHarness harness;
        auto data1 = Random::bytes(31);
        auto data2 = Random::bytes<80>();
        auto recv2 = std::array<uint8_t, 80>();
        auto sHandle1 = harness.newStream(false);
        assertSuccess(quib_send_data(sHandle1, data1.data(), data1.size(), true));
        tick();

        auto server = startServer(harness.receiveFromClient());
        auto stream1 = server->assertStream();
        assertThat("You transmitted initial data", stream1->isReceivedExactlyUpTo(data1.size()));
        assertThat("You set the final flag on initial data", stream1->isReceiveComplete());
        assertThat("Initial data is correct", stream1->getReceivedData() == data1);

        auto stream2 = server->newStream(false);
        stream2->sendData(data2.data(), data2.size());
        stream2->markSendComplete();
        
        harness.normalTick(server);
        auto sHandle2 = harness.acceptStream();
        size_t n; bool final;
        assertSuccess(quib_receive_data(sHandle2, recv2.data(), recv2.size(), &n, &final));
        assertEquals("You received initial data", n, 80u);
        assertThat("You set the final flag", final);
        assertThat("Initial data is correct", recv2 == data2);
    }},
    { "unordered_receipt", []() {
        auto [harness, server] = startServer();
        auto stream = server->newStream(false);
        stream->sendData({0x01});
        auto p1 = server->sendPackets();
        stream->sendData({0x02});
        auto p2 = server->sendPackets();
        stream->sendData({0x03});
        auto p3 = server->sendPackets();
        stream->sendData({0x04});
        auto p4 = server->sendPackets();
        stream->sendData({0x05});
        stream->markSendComplete();
        auto p5 = server->sendPackets();

        harness->sendToClient(p1);
        harness->sendToClient(p3);
        harness->sendToClient(p5);
        server->considerYourPacketLost(p3); // send these twice
        server->considerYourPacketLost(p1);
        harness->normalTick(server);

        auto sHandle = harness->acceptStream();
        uint8_t buf[5];
        bool isFinal;
        size_t nRecv;
        assertSuccess(quib_receive_data(sHandle, buf, 5, &nRecv, &isFinal));
        assertEquals("You did not offer any extra data when data at index 1 is missing", nRecv, 1u);
        assertThat("You also did not prematurely set final = true", !isFinal);
        
        harness->sendToClient(p4);
        harness->normalTick(server);
        assertSuccess(quib_receive_data(sHandle, buf+1, 4, &nRecv, &isFinal));
        assertEquals("You did not offer any extra data even though index 3 arrived now", nRecv, 0u);
        assertThat("You also still did not prematurely set final = true", !isFinal);

        harness->sendToClient(p2);
        harness->normalTick(server);
        assertSuccess(quib_receive_data(sHandle, buf+1, 4, &nRecv, &isFinal));
        assertEquals("Once the data at index 1 arrived, you reassembled offered everything", nRecv, 4u);
        assertThat("You properly set final = true", isFinal);
        assertThat("The received data is correct", !memcmp(buf, std::vector<uint8_t>{0x01,0x02,0x03,0x04,0x05}.data(), 5));
    }},
    { "complex_ack", [] {
        auto [harness, server] = startServer();

        std::vector<std::pair<uint32_t, uint32_t>> ranges = {{2500,2501},{5,192},{7999999,8000050}};
        for (auto const& [low, high] : ranges) {
            for (uint32_t i=low; i<high; ++i) {
                QUIBPacket packet;
                packet.destinationConnectionId = server->getPeerConnectionId();
                packet.packetNumber = i;
                packet.payload.emplace_back(std::make_unique<PINGFrame>());
                harness->sendToClient(packet);
            }
        }
        tick();
        
        std::unique_ptr<ACKFrame const> theFrame = nullptr;
        for (QUIBPacket& packet : harness->receiveFromClient()) {
            server->receivePacket(packet);
            for (auto& framePtr : packet.payload) {
                if (auto* it = dynamic_cast<ACKFrame const*>(framePtr.get())) {
                    assertThat("You only sent a single ACK frame", !theFrame);
                    framePtr.release();
                    theFrame.reset(it);
                }
            }
        }
        assertThat("You sent an ACK frame", theFrame != nullptr);
        ranges.push_back({0,1}); // the initial frame from the server is also unacknowledged
        assertEquals("You acknowledged the correct ranges", std::set(ranges.begin(), ranges.end()), std::set(theFrame->ranges.begin(), theFrame->ranges.end()));
    }},
    { "undersized_reads", []() {
        auto [harness, server] = startServer();
        auto stream = server->newStream(false);
        auto data = Random::bytes(64);
        stream->sendData(data);
        stream->markSendComplete();
        harness->forwardFrom(server);
        tick();
        
        auto sHandle = harness->acceptStream();
        uint8_t buf; size_t n; bool final;
        for (uint8_t i=0;i<64;++i) {
            ContextHandle h("i=",i);
            assertSuccess(quib_receive_data(sHandle, &buf, 1, &n, &final));
            assertEquals("Read size is correct", n, 1u); n = 0;
            assertEquals("Data is correct", buf, data[i]); buf = 0x42;
            assertThat("Final flag is correct", (final == (i == 63))); final = true;
        }
        ensure_timeout();
    }},
    { "oversized_reads", []() {
        auto [harness, server] = startServer();
        auto stream = server->newStream(false);
        auto data = Random::bytes(256);
        stream->sendData(data.data(), 128);
        harness->normalTick(server);
        stream->sendData(data.data()+128, 128);
        stream->markSendComplete();
        harness->normalTick(server);

        auto sHandle = harness->acceptStream();
        uint8_t buf[300]; size_t n; bool final;
        assertSuccess(quib_receive_data(sHandle, buf, 300, &n, &final));
        assertEquals("Read size is correct", n, 256u);
        assertThat("Final flag is set", final);
        assertThat("Data is correct", !memcmp(data.data(), buf, 256));
    }},
    { "intermediate_chunk_nack", []() {
        auto [harness, server] = startServer();
        auto sHandle = harness->newStream(true);
        assertSuccess(quib_send_data(sHandle, "32", 2, false));
        harness->normalTick(server);
        
        auto stream = server->assertStream();
        assertThat("The stream is bidirectional", stream->isServerSendCapableId());
        assertThat("You sent data on the stream", stream->isRangeReceived(0,2));
        assertThat("The data you sent is correct", !memcmp(stream->getReceivedData().data(), "32", 2));
        auto lostAckPackets = server->sendPackets(); /* oops, these will get dropped */

        assertSuccess(quib_send_data(sHandle, "973", 1, true));
        harness->forwardFrom(server);
        tick();
        std::unique_ptr<STREAMFrame const> theFrame = nullptr;
        for (QUIBPacket& packet : harness->receiveFromClient()) {
            server->receivePacket(packet);
            for (auto& framePtr : packet.payload) {
                if (auto* it = dynamic_cast<STREAMFrame const*>(framePtr.get())) {
                    assertThat("You only sent a single STREAM frame with the data", !theFrame);
                    framePtr.release();
                    theFrame.reset(it);
                }
            }
        }
        assertThat("You sent the remaining data", theFrame != nullptr);
        assertEquals("You did not re-send the previous data before it has timed out", theFrame->offset, 2u);
        assertEquals("You sent the right amount of data", theFrame->data.size(), 1u);
        assertThat("You sent the right data", !memcmp(theFrame->data.data(), "9", 1));
        assertThat("You set the final flag", theFrame->isFinal == true);

        assertThat("You sent the remaining data on the stream", stream->isReceivedExactlyUpTo(3));
        assertThat("You set the final flag", stream->isReceiveComplete());
        assertThat("The data you sent is correct", !memcmp(stream->getReceivedData().data(), "329", 3));

        harness->forwardFrom(server);
        tick();
        theFrame = nullptr;
        for (QUIBPacket& packet : harness->receiveFromClient()) {
            server->receivePacket(packet);
            for (auto& framePtr : packet.payload) {
                if (auto* it = dynamic_cast<STREAMFrame const*>(framePtr.get())) {
                    assertThat("You only sent a single STREAM frame with the re-sent data", !theFrame);
                    framePtr.release();
                    theFrame.reset(it);
                }
            }
        }
        assertThat("You re-sent the data", theFrame != nullptr);
        assertEquals("You only re-sent the missing data", theFrame->offset, 0u);
        assertEquals("You only re-sent the missing data", theFrame->data.size(), 2u);
        assertThat("You did not set the final flag", !theFrame->isFinal);
        assertThat("The data you sent is correct", !memcmp(theFrame->data.data(), "32", 2));

        harness->forwardFrom(server);
        tick();
        for (QUIBPacket const& packet : harness->receiveFromClient()) {
            server->receivePacket(packet);
            assertThat("Once the data was acknowledged you did not send it again", forall(packet.payload, [](std::unique_ptr<QUIBFrame> const& fp) { return (dynamic_cast<STREAMFrame*>(fp.get()) == nullptr); }));
        }
    }},
    { "final_chunk_nack", []() {
        auto [harness, server] = startServer();
        auto sHandle = harness->newStream(false);
        assertSuccess(quib_send_data(sHandle, "42", 2, false));
        harness->normalTick(server);

        auto stream = server->assertStream();
        assertThat("The stream is unidirectional", !stream->isServerSendCapableId());
        assertThat("You sent data on the stream", stream->isRangeReceived(0,2));
        assertThat("The data you sent is correct", !memcmp(stream->getReceivedData().data(), "42", 2));

        harness->forwardFrom(server);
        tick();
        auto packets = harness->receiveFromClient();
        assertThat("You are no longer sending the data that was ACK'd", forall(packets, [](QUIBPacket const& p) {
            return forall(p.payload, [](std::unique_ptr<QUIBFrame> const& fp) { return (dynamic_cast<STREAMFrame*>(fp.get()) == nullptr); });
        }));
        for (auto const& packet: packets) server->receivePacket(packet);

        assertSuccess(quib_send_data(sHandle, "210", 2, true));
        harness->normalTick(server);
        assertThat("You sent the remaining data on the stream", stream->isReceivedExactlyUpTo(4));
        assertThat("You set the final flag", stream->isReceiveComplete());
        assertThat("The data you sent is correct", !memcmp(stream->getReceivedData().data(), "4221", 4));
        
        auto lostAckPackets = server->sendPackets();
        server->considerYourPacketLost(lostAckPackets);
        tick(3);
        // ... by now you should definitely consider the packet lost, let's see if you re-sent it correctly (and only once)
        std::unique_ptr<STREAMFrame const> theFrame = nullptr;
        for (QUIBPacket& packet : harness->receiveFromClient()) {
            for (auto& framePtr : packet.payload) {
                if (auto* it = dynamic_cast<STREAMFrame const*>(framePtr.get())) {
                    assertThat("You did not send multiple STREAM frames when the data was timed out only once", !theFrame);
                    framePtr.release();
                    theFrame.reset(it);
                }
            }
        }
        assertThat("You re-sent the data after it had timed out", theFrame != nullptr);
        assertThat("You only re-sent the data that was lost", (theFrame->offset == 2));
        assertThat("You set the final flag on the re-sent data", (theFrame->isFinal == true));
        assertThat("You re-sent the correct amount of data", theFrame->data.size() == 2);
        assertThat("You re-sent the correct data", !memcmp(theFrame->data.data(), "21", 2));
    }},
    { "final_size_violation_down", []() {
        auto [harness, server] = startServer();
        auto streamId = server->newStream(false)->getStreamId();
        harness->sendToClient(server->decorateToPacket<STREAMFrame>([streamId](STREAMFrame* f) {
            f->data.resize(4);
            f->streamId = streamId;
            f->offset = 0;
            f->isFinal = true;
        }));
        tick();
        harness->sendToClient(server->decorateToPacket<STREAMFrame>([streamId](STREAMFrame* f) {
            f->data.resize(3);
            f->streamId = streamId;
            f->offset = 0;
            f->isFinal = true;
        }));
        tick();
        harness->forwardTo(server);
        assertEquals("You closed the connection", server->getExitCodeIfClosed(), FINAL_SIZE_ERROR);
    }},
    { "final_size_violation_up", []() {
        auto [harness, server] = startServer();
        auto streamId = server->newStream(false)->getStreamId();
        harness->sendToClient(server->decorateToPacket<STREAMFrame>([streamId](STREAMFrame* f) {
            f->data.resize(4);
            f->streamId = streamId;
            f->offset = 0;
            f->isFinal = true;
        }));
        tick();
        harness->sendToClient(server->decorateToPacket<STREAMFrame>([streamId](STREAMFrame* f) {
            f->data.resize(4);
            f->streamId = streamId;
            f->offset = 1;
            f->isFinal = true;
        }));
        tick();
        harness->forwardTo(server);
        assertEquals("You closed the connection with FINAL_SIZE_ERROR.", server->getExitCodeIfClosed(), FINAL_SIZE_ERROR);
    }},
    { "empty_payload", []() {
        TestHarness harness;
        tick();
        auto packets = harness.receiveFromClient();
        assertThat("You sent an initial packet", !packets.empty());
        assertEquals("You only sent a single initial packet", packets.size(), 1u);
        auto const& initialPacket = packets.front();
        assertThat("The initial packet's packet number is zero", initialPacket.packetNumber == 0);
        assertThat("The initial packet is marked as such", initialPacket.isInitial());

        QUIBPacket packet;
        packet.sourceConnectionId = Random::bytes<160>();
        packet.destinationConnectionId = *initialPacket.sourceConnectionId;
        packet.packetNumber = 0;
        harness.sendToClient(packet);
        tick();
        assertThat("You did not successfully establish a connection, since the reply packet was ill-formed (empty payload)", !quib_is_connected(harness));
    }},
    { "no_initial_reply", []() {
        TestHarness harness;
        tick();
        auto packets = harness.receiveFromClient();
        assertThat("You sent an initial packet", !packets.empty());
        assertEquals("You only sent a single initial packet", packets.size(), 1u);
        auto const& initialPacket = packets.front();
        assertThat("The initial packet's packet number is zero", initialPacket.packetNumber == 0);
        assertThat("The initial packet is marked as such", initialPacket.isInitial());

        auto server = startServer(initialPacket);
        auto serverReply = server->sendPackets();
        for (auto& p : serverReply) p->sourceConnectionId = std::nullopt;

        harness.sendToClient(serverReply);
        tick();
        assertThat("You did not successfully establish a connection, since the reply packet was ill-formed (not marked as initial)", !quib_is_connected(harness));
    }},
    { "send_to_readonly", []() {
        auto [harness, server] = startServer();
        auto stream = server->newStream(false);
        stream->sendData({0x01});
        harness->normalTick(server);

        auto sHandle = harness->acceptStream();
        assertEquals("This attempt should fail, since stream is unidirectional and server-initiated", quib_send_data(sHandle, "asdf", 4, true), ERR_READ_ONLY_STREAM);
    }},
    { "recv_from_writeonly", []() {
        auto [harness, server] = startServer();
        auto sHandle = harness->newStream(false);
        assertSuccess(quib_send_data(sHandle, "a", 1, false));
        harness->normalTick(server);

        auto stream = server->assertStream();
        assertThat("This is a client-initiated unidirectional stream.", !stream->isServerSendCapableId());
        uint8_t buf[1];
        size_t n; bool final;
        assertEquals("Attempts to read from a client-initiated unidirectional stream should fail", quib_receive_data(sHandle, buf, 1, &n, &final), ERR_WRITE_ONLY_STREAM);
    }},
    { "multiple_connections_incoming", []() {
        auto [harness1, server1] = startServer();
        auto [harness2, server2] = startServer();
        auto data1 = Random::bytes(25 * 1024);
        auto data2 = Random::bytes(19 * 1024);
        auto recv1 = std::vector<uint8_t>(); recv1.resize(data1.size()+1);
        auto recv2 = std::vector<uint8_t>(); recv2.resize(data2.size()+1);

        auto doTick = [&]() { harness1->forwardFrom(server1); harness2->forwardFrom(server2); tick(); harness1->forwardTo(server1); harness2->forwardTo(server2); };

        auto stream1 = server1->newStream(false);
        auto stream2 = server2->newStream(false);
        stream2->sendData(data2.data(), 9*1024);
        doTick();

        auto sHandle2 = harness2->acceptStream();
        size_t n; bool final;
        assertSuccess(quib_receive_data(sHandle2, recv2.data(), 19*1024, &n, &final));
        assertEquals("Received data size", n, 9*1024u);
        assertThat("Not prematurely marked as final", !final);

        stream1->sendData(data1.data(), 5*1024);
        stream2->sendData(data2.data()+9*1024, 1*1024);
        doTick();
        auto sHandle1 = harness1->acceptStream();
        assertSuccess(quib_receive_data(sHandle1, recv1.data(), 25*1024, &n, &final));
        assertEquals("Received data size", n, 5*1024u);
        assertThat("Not prematurely marked as final", !final);
        assertSuccess(quib_receive_data(sHandle2, recv2.data()+9*1024, 10*1024, &n, &final));
        assertEquals("Received data size", n, 1*1024u);
        assertThat("Not prematurely marked as final", !final);
        
        stream1->sendData(data1.data()+5*1024, 3*1024);
        doTick();
        assertSuccess(quib_receive_data(sHandle1, recv1.data()+5*1024, 20*1024, &n, &final));
        assertEquals("Received data size", n, 3*1024u);
        assertThat("Not prematurely marked as final", !final);
        assertSuccess(quib_receive_data(sHandle2, recv2.data()+10*1024, 9*1024, &n, &final));
        assertEquals("Received data size", n, 0*1024u);
        assertThat("Not prematurely marked as final", !final);

        stream1->sendData(data1.data()+8*1024, 7*1024);
        doTick();
        stream2->sendData(data2.data()+10*1024, 9*1024);
        doTick();
        stream1->sendData(data1.data()+15*1024, 10*1024);
        stream2->markSendComplete();
        doTick();
        assertSuccess(quib_receive_data(sHandle1, recv1.data()+8*1024, 17*1024, &n, &final));
        assertEquals("Received data size", n, 17*1024u);
        assertThat("Not prematurely marked as final", !final);
        assertSuccess(quib_receive_data(sHandle2, recv2.data()+10*1024, 9*1024, &n, &final));
        assertEquals("Received data size", n, 9*1024u);
        assertThat("Marked as final", final);

        stream1->markSendComplete();
        doTick();
        assertSuccess(quib_receive_data(sHandle1, recv1.data()+25*1024, 1, &n, &final));
        assertEquals("Received data size", n, 0u);
        assertThat("Marked as final", final);
        assertSuccess(quib_receive_data(sHandle2, recv2.data()+19*1024, 1, &n, &final));
        assertEquals("Received data size", n, 0u);
        assertThat("Still marked as final", final);

        recv1.resize(data1.size());
        recv2.resize(data2.size());
        assertThat("Data was correctly transmitted", data1 == recv1);
        assertThat("Data was correctly transmitted", data2 == recv2);
    }},
    { "multiple_connections_outgoing", []() {
        auto [harness1, server1] = startServer();
        auto [harness2, server2] = startServer();
        auto data1 = Random::bytes(25 * 1024);
        auto data2 = Random::bytes(31 * 1024);

        auto doTick = [&]() { harness1->forwardFrom(server1); harness2->forwardFrom(server2); tick(); harness1->forwardTo(server1); harness2->forwardTo(server2); };

        auto sHandle1 = harness1->newStream(false);
        auto sHandle2 = harness2->newStream(false);

        assertSuccess(quib_send_data(sHandle2, data2.data(), 1 * 1024, false));
        doTick();
        auto stream2 = server2->assertStream();
        assertThat("Transmission is progressing", stream2->isReceivedExactlyUpTo(1 * 1024));

        assertSuccess(quib_send_data(sHandle1, data1.data(), 3 * 1024, false));
        doTick();
        auto stream1 = server1->assertStream();
        assertThat("Transmission is progressing", stream1->isReceivedExactlyUpTo(3 * 1024));

        assertSuccess(quib_send_data(sHandle2, data2.data() + 1*1024, 6 * 1024, false));
        assertSuccess(quib_send_data(sHandle1, data1.data() + 3*1024, 6 * 1024, false));
        doTick();
        assertThat("Transmission is progressing", stream1->isReceivedExactlyUpTo(9*1024));
        assertThat("Transmission is progressing", stream2->isReceivedExactlyUpTo(7*1024));
        
        assertSuccess(quib_send_data(sHandle1, data1.data() + 9*1024, 4*1024, false));
        assertSuccess(quib_send_data(sHandle2, data2.data() + 7*1024, 5*1024, false));
        assertSuccess(quib_send_data(sHandle1, data1.data() + 13*1024, 3*1024, false));
        doTick();
        assertThat("Transmission is progressing", stream1->isReceivedExactlyUpTo(16*1024));
        assertThat("Transmission is progressing", stream2->isReceivedExactlyUpTo(12*1024));

        assertSuccess(quib_send_data(sHandle1, data1.data()+16*1024, 8*1024, false));
        assertSuccess(quib_send_data(sHandle2, data2.data()+12*1024, 19*1024, true));
        doTick();
        assertThat("Transmission is progressing", stream1->isReceivedExactlyUpTo(24*1024) && !stream1->isReceiveComplete());
        assertThat("Transmission is progressing", stream2->isReceivedExactlyUpTo(31*1024) && stream2->isReceiveComplete());

        assertSuccess(quib_send_data(sHandle1, data1.data()+24*1024, 1*1024, true));
        doTick();
        assertThat("Transmission is progressing", stream1->isReceivedExactlyUpTo(25*1024) && stream1->isReceiveComplete());

        assertThat("Data is correct", data1 == stream1->getReceivedData());
        assertThat("Data is correct", stream2->isReceivedExactlyUpTo(31*1024) && (data2 == stream2->getReceivedData()));
    }},
    { "discard_before_finalize", []() {
        auto [harness, server] = startServer();
        auto sHandle1 = harness->newStream(false);
        assertSuccess(quib_send_data(sHandle1, "f", 1, false));
        harness->normalTick(server);
        auto stream1 = server->assertStream();

        auto sHandle2 = harness->newStream(false);
        assertSuccess(quib_send_data(sHandle2, "x", 1, false));
        assertSuccess(quib_send_data(sHandle1, "oobar", 5, true));
        harness->discard();
        assertEquals("The connection has been closed, so attempts to write to its streams should fail", quib_send_data(sHandle2, "d", 1, true), ERR_CONNECTION_CLOSED);

        harness->normalTick(server);

        assertThat("You have not prematurely closed the connection (there is unacknowledged data on stream 1)", !server->isClosed());
        auto lostPackets = server->sendPackets(); /* oops, i dropped the ACK frame, how clumsy */

        // let's give you some time to realize it is dropped, resend it
        harness->normalTick(server); // tick t+1
        harness->normalTick(server); // tick t+2, you declare it as lost and resend it
        harness->normalTick(server); // tick t+3, you receive the acknowledgement, and close the connection

        assertEquals("The connection has been closed with exit code zero", server->getExitCodeIfClosed(), 0);
        assertThat("You correctly sent the data", stream1->isReceiveComplete() && stream1->isReceivedExactlyUpTo(6) && !memcmp(stream1->getReceivedData().data(), "foobar", 6));
    }},
    { "stream_interleaving", [](){
        auto [harness, server] = startServer();
        for (uint8_t i=0; i<4; ++i) {
            auto sHandle1 = harness->newStream(true);
            auto stream2 = server->newStream(true);
            auto data1SC = Random::bytes<32>();
            auto data1CS = Random::bytes(32);
            auto data2SC = Random::bytes<32>();
            auto data2CS = Random::bytes(32);
            std::array<uint8_t, 32> recv1, recv2;
            auto data1SCIt = data1SC.begin();
            auto data1CSIt = data1CS.begin()+1;
            auto data2SCIt = data2SC.begin()+1;
            auto data2CSIt = data2CS.begin();
            auto recv1It = recv1.begin();
            auto recv2It = recv2.begin();

            assertSuccess(quib_send_data(sHandle1, data1CS.data(), 1, false));
            stream2->sendData(data2SC.data(), 1);

            harness->normalTick(server);

            auto stream1 = server->assertStream(2*(i+1));
            auto sHandle2 = harness->acceptStream();

            for (uint8_t const v : Random::bytes<0xffff>()) {
                harness->normalTick(server);
                uint8_t x;
                for (x=0; x<6; ++x) {
                    uint8_t const c = (x+v)%6;
                    if ((data1SCIt != data1SC.end()) && (c == 0)) {
                        frameworkDebug("Choice: S->C on 1\n");
                        uint8_t byte = *(data1SCIt++);
                        stream1->sendData(&byte, 1);
                        if (data1SCIt == data1SC.end()) stream1->markSendComplete();
                        break;
                    }
                    if ((data2SCIt != data2SC.end()) && (c == 1)) {
                        frameworkDebug("Choice: S->C on 2\n");
                        uint8_t byte = *(data2SCIt++);
                        stream2->sendData(&byte, 1);
                        if (data2SCIt == data2SC.end()) stream2->markSendComplete();
                        break;
                    }
                    if ((data1CSIt != data1CS.end()) && (c == 2)) {
                        frameworkDebug("Choice: C->S on 1\n");
                        uint8_t byte = *(data1CSIt++);
                        assertSuccess(quib_send_data(sHandle1, &byte, 1, data1CSIt == data1CS.end()));
                        break;
                    }
                    if ((data2CSIt != data2CS.end()) && (c == 3)) {
                        frameworkDebug("Choice: C->S on 2\n");
                        uint8_t byte = *(data2CSIt++);
                        assertSuccess(quib_send_data(sHandle2, &byte, 1, data2CSIt == data2CS.end()));
                        break;
                    }
                    if ((recv1It != recv1.end()) && (c == 4)) {
                        frameworkDebug("Choice: receive on 1\n");
                        size_t nRecv; bool final;
                        assertSuccess(quib_receive_data(sHandle1, &*recv1It, 1, &nRecv, &final));
                        assertThat("You did not return more data than was requested", nRecv <= 1);
                        if (nRecv) ++recv1It;
                        assertThat("The final flag is correct", final == (recv1It == recv1.end()));
                        break;
                    }
                    if (recv2It != recv2.end() && (c == 5)) {
                        frameworkDebug("Choice: receive on 2\n");
                        size_t nRecv; bool final;
                        assertSuccess(quib_receive_data(sHandle2, &*recv2It, 1, &nRecv, &final));
                        assertThat("You did not return more data than was requested", nRecv <= 1);
                        if (nRecv) ++recv2It;
                        assertThat("The final flag is correct", final == (recv2It == recv2.end()));
                        break;
                    }
                }
                if (x == 6) break;
            }
            harness->normalTick(server);
            assertThat("You set the final flags on the sending parts", stream1->isReceiveComplete() && stream2->isReceiveComplete());
            assertThat("You send the correct amount of data", stream1->isReceivedExactlyUpTo(32) && stream2->isReceivedExactlyUpTo(32));
            assertThat("You transmitted the correct data", (stream1->getReceivedData() == data1CS) && (stream2->getReceivedData() == data2CS));
            assertThat("You received the correct data", (recv1 == data1SC) && (recv2 == data2SC));
        }
    }},
    { "reset_stream_complete", []() {
        auto [harness, server] = startServer();
        quib_stream* sHandle;
        assertSuccess(quib_new_stream(*harness, &sHandle, false));
        assertSuccess(quib_send_data(sHandle, "f", 1, false));
        harness->normalTick(server);
        auto stream = server->assertStream();
        assertSuccess(quib_send_data(sHandle, "oobar", 5, true));
        quib_discard_stream(sHandle);
        harness->sendToClient(server->sendPackets());
        tick();
        (void)harness->receiveFromClient(); // oops i dropped it
        harness->normalTick(server);
        harness->normalTick(server);
        harness->normalTick(server);
        assertThat("You did not send RESET_STREAM", stream->isClientSendOpen());
        assertThat("Both data and final flag were received", stream->isReceiveComplete() && stream->isReceivedExactlyUpTo(6));
        assertThat("You transmitted the data correctly", !memcmp(stream->getReceivedData().data(), "foobar", 6));
    }},
    { "reset_stream_incomplete", []() {
        auto [harness, server] = startServer();
        quib_stream* sHandle;
        assertSuccess(quib_new_stream(*harness, &sHandle, false));
        assertSuccess(quib_send_data(sHandle, "f", 1, false));
        harness->normalTick(server);
        auto stream = server->assertStream();
        assertSuccess(quib_send_data(sHandle, "oobar", 5, false));
        quib_discard_stream(sHandle);
        harness->normalTick(server);
        assertThat("You sent RESET_STREAM", !stream->isClientSendOpen());
        assertThat("You did not transmit any data after the stream was cancelled", stream->isReceivedExactlyUpTo(1));
    }},
    { "reset_stream_incomplete_2", []() {
        auto [harness, server] = startServer();
        quib_stream* sHandle;
        assertSuccess(quib_new_stream(*harness, &sHandle, false));
        assertSuccess(quib_send_data(sHandle, "f", 1, false));
        harness->normalTick(server);
        auto stream = server->assertStream();
        assertSuccess(quib_send_data(sHandle, "oobar", 5, false));
        quib_discard_stream(sHandle);
        harness->sendToClient(server->sendPackets());
        tick();
        (void)harness->receiveFromClient(); // oops i dropped it
        harness->normalTick(server);
        harness->normalTick(server);
        harness->normalTick(server);
        assertThat("You (re-)sent RESET_STREAM", !stream->isClientSendOpen());
        assertThat("You did not (re-)transmit any data after the stream was cancelled", stream->isReceivedExactlyUpTo(1));
    }},
    { "stop_sending_outgoing", []() {
        auto [harness, server] = startServer();
        auto sHandle = harness->newStream(false);
        assertSuccess(quib_send_data(sHandle, "f", 1, false));
        harness->normalTick(server);
        auto stream = server->assertStream();
        assertSuccess(quib_send_data(sHandle, "oobar", 5, false));
        harness->sendToClient(server->sendPackets());
        tick();
        (void)harness->receiveFromClient(); // oops i dropped it
        stream->terminateClientSend();
        harness->normalTick(server); // you receive STOP_SENDING
        harness->normalTick(server); // you realize the packet was dropped (but should not re-send anything)
        harness->normalTick(server); // for good measure
        assertThat("You did not (re-)transmit any data after the stream was cancelled", stream->isReceivedExactlyUpTo(1));
    }},
    { "stop_sending_incoming", []() {
        auto [harness, server] = startServer();
        auto stream = server->newStream(false);
        stream->sendData({'a'});
        harness->normalTick(server);
        {
            (void)harness->acceptStream(); // accept + discard
        }

        harness->normalTick(server);
        assertThat("You sent STOP_SENDING", !stream->isServerSendOpen());
    }},
    { "stop_sending_incoming_2", []() {
        auto [harness, server] = startServer();
        auto stream = server->newStream(false);
        stream->sendData({'a'});
        harness->normalTick(server);
        {
            (void)harness->acceptStream(); // accept + discard
        }
        harness->forwardFrom(server);
        tick();
        (void)harness->receiveFromClient(); // oops

        harness->normalTick(server);
        harness->normalTick(server);
        harness->normalTick(server);
        assertThat("You re-sent STOP_SENDING", !stream->isServerSendOpen());
    }},
    { "reset_stream_incoming", []() {
        auto [harness, server] = startServer();
        auto stream = server->newStream(false);
        stream->sendData({'a'});
        harness->normalTick(server);
        auto sHandle = harness->acceptStream();
        size_t nRecv; bool isFinal;
        assertSuccess(quib_receive_data(sHandle, nullptr, 0, &nRecv, &isFinal));
        stream->terminateServerSend();
        harness->normalTick(server);
        assertEquals("Attempts to read from the reset stream should fail", quib_receive_data(sHandle, nullptr, 0, &nRecv, &isFinal), ERR_STREAM_RESET);
    }},
    { "stream_state_error", []() {
        auto [harness, server] = startServer();
        assertThat("You did not open any unprompted streams", server->streams().empty());
        harness->sendToClient(server->decorateToPacket<STREAMFrame>([](STREAMFrame* f) {
            f->data.resize(4);
            f->streamId = 0;
            f->offset = 0;
            f->isFinal = true;
        }));
        tick();
        harness->forwardTo(server);
        assertEquals("You closed the connection", server->getExitCodeIfClosed(), STREAM_STATE_ERROR);
    }},
    { "unknown_frame_type", []() {
        auto [harness, server] = startServer();
        assertThat("You did not open any unprompted streams", server->streams().empty());
        auto packet = server->decorateToPacket<PINGFrame>([](PINGFrame*) {});
        auto encoded = encodeQUIBPacket(packet);
        encoded.back() = 0x42;
        harness->serverToClientQueue.emplace_back(std::move(encoded));
        tick();
        harness->forwardTo(server);
        assertEquals("You closed the connection", server->getExitCodeIfClosed(), FRAME_ENCODING_ERROR);
    }},
    { "discard_null", []() {
        auto [harness, server] = startServer();
        quib_discard_connection(nullptr);
        auto sHandle = harness->newStream(false);
        quib_discard_stream(nullptr);
        quib_discard_connection(nullptr);
        assertSuccess(quib_send_data(sHandle, "message", 7, true));
        harness->normalTick(server);
        auto stream = server->assertStream();
        assertThat("Data was transferred", stream->isReceivedExactlyUpTo(7) && stream->isReceiveComplete() && !memcmp(stream->getReceivedData().data(), "message", 7));
    }},
};
constexpr size_t N_TESTS = sizeof(TESTS)/sizeof(*TESTS);

// END TEST DEFINITIONS

}

udp_socket* udp_open(ip_address peerAddr, udp_port peerPort) {
    using namespace __CONTest;
    auto socket = new udp_socket();
    if (auto it = std::find_if(TestHarness::live.begin(), TestHarness::live.end(), [peerAddr, peerPort](TestHarness* it) { return ((it->peer.address == peerAddr) && (it->peer.port == peerPort)); }); it != TestHarness::live.end()) {
        (*it)->sockets.insert(socket);
        socket->harness = (*it);
    }
    frameworkDebug("UDP socket opened: udp_socket* = %p\n", socket);
    return socket;
}
void udp_close(udp_socket* socket) {
    frameworkDebug("UDP socket closed: udp_socket* = %p\n", socket);
    if (!socket) return;
    if (socket->harness) socket->harness->sockets.erase(socket);
    delete socket;
}
size_t udp_receive_datagram(udp_socket* socket, uint8_t* pBuf, size_t szBuf) {
    using namespace __CONTest;
    assertThat("you are not receiving packets outside of quib_tick", __CONTest::isTicking);
    if (socket->harness) {
        if (!socket->harness->serverToClientQueue.empty()) {
            frameworkDebug("giving you a datagram\n");
            auto& packet = socket->harness->serverToClientQueue.front();
            size_t const packetSize = packet.size();
            assertThat("your receive buffer is large enough (should be at least 3MB)", packetSize <= szBuf);
            memcpy(pBuf, packet.data(), packetSize);
            socket->harness->serverToClientQueue.pop_front();
            return packetSize;
        }
    }
    return 0;
}
void udp_send_datagram(udp_socket* socket, uint8_t const* pData, size_t szData) {
    assertThat("you are not sending packets outside of quib_tick", __CONTest::isTicking);
    if (socket->harness) {
        auto& vec = socket->harness->clientToServerQueue.emplace_back();
        vec.resize(szData);
        memcpy(vec.data(), pData, szData);
    }
}

int main(int argc, char const** argv)
{
    if (argc != 2) {
        printf("Don't run this directly. Use \"make test\".\n");
        return 2;
    }
    
    std::string_view name = argv[1];
    for (size_t i=0; i<__CONTest::N_TESTS; ++i) {
        if (name != __CONTest::TESTS[i].first) continue;
        try {
            __CONTest::TESTS[i].second();
            return 0;
        } catch (__CONTest::Skip const& s) {
            return 1;
        } catch (std::string const& failure) {
            fprintf(stderr, "%s\n", failure.c_str());
            return 4;
        }
    }
    fprintf(stderr, "INVALID TEST NAME: %s\n", argv[1]);
    return 1;
}
