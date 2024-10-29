#pragma once
#include <cstdint>
#include <vector>
#include <array>
#include <optional>
#include <set>
#include <string>
#include <memory>
#include <random>
#include <cstdio>
#include "test_shared.h"

/** These are for internal use (by the test system) only. You must not use them in your submission! */

namespace __CONTest {

class Random {
    public:
        static uint8_t byte() { return _dist8(_generator); }

        static void bytes(uint8_t* buf, size_t n) {
            FILE* fp = fopen("/dev/urandom", "rb");
            size_t toRead = n;
            while (toRead) {
                if (feof(fp) || ferror(fp)) throw std::string("Failed to read from /dev/urandom??");
                size_t nRead = fread(buf, 1, toRead, fp);
                toRead -= nRead;
            }
            fclose(fp);
        }

        template<size_t N> static std::array<uint8_t, N> bytes() {
            std::array<uint8_t, N> buf;
            bytes(buf.data(), N);
            return buf;
        }

        static std::vector<uint8_t> bytes(size_t N) {
            std::vector<uint8_t> buf;
            buf.resize(N);
            bytes(buf.data(), N);
            return buf;
        }

        static uint64_t number() { return _dist64(_generator); }
        static uint64_t number(uint64_t max) {
            return _dist64(_generator, decltype(_dist64)::param_type(0,max-1));
        }
        static uint64_t number(uint64_t min, uint64_t max) { return min+number(max-min); }

        static void reseed(std::random_device::result_type s) { _generator = std::mt19937(s); }
    
    private:
        static std::mt19937 _generator;
        static std::uniform_int_distribution<uint8_t> _dist8;
        static std::uniform_int_distribution<uint64_t> _dist64;
};

struct QUIBFrame {
    virtual ~QUIBFrame() = default;
    virtual size_t byteSize() const = 0;
};
struct PINGFrame final : QUIBFrame {
    size_t byteSize() const override;
};
struct ACKFrame final : QUIBFrame {
    size_t byteSize() const override;
    std::vector<std::pair<uint32_t, uint32_t>> ranges;
};
struct STREAMFrame final : QUIBFrame {
    size_t byteSize() const override;
    uint32_t streamId;
    uint32_t offset;
    bool isFinal;
    std::vector<uint8_t> data;
};
struct MAXSTREAMDATAFrame final : QUIBFrame {
    size_t byteSize() const override;
    uint32_t streamId;
    uint32_t newMaxSize;
};
struct RESETSTREAMFrame final : QUIBFrame {
    size_t byteSize() const override;
    uint32_t streamId;
};
struct STOPSENDINGFrame final : QUIBFrame {
    size_t byteSize() const override;
    uint32_t streamId;
};
struct CONNECTIONCLOSEFrame final : QUIBFrame {
    size_t byteSize() const override;
    uint8_t errorCode;
};

struct QUIBPacket {
    uint32_t packetNumber;
    std::array<uint8_t, 160> destinationConnectionId;
    std::optional<std::array<uint8_t,160>> sourceConnectionId;
    bool isInitial() const { return sourceConnectionId.has_value(); }
    std::vector<std::unique_ptr<QUIBFrame>> payload;
};

QUIBPacket parseQUIBPacket(uint8_t const* data, size_t size);
static inline QUIBPacket parseQUIBPacket(std::vector<uint8_t> const& data) {
    return parseQUIBPacket(data.data(), data.size());
}
std::vector<uint8_t> encodeQUIBPacket(QUIBPacket const&);

struct QUIBStream {
    virtual ~QUIBStream() = default;
    virtual uint32_t getStreamId() const = 0;
    virtual bool isClientSendCapableId() const = 0;
    virtual bool isServerSendCapableId() const = 0;
    virtual bool isClientSendOpen() const = 0;
    virtual bool isServerSendOpen() const = 0;

    virtual void terminateClientSend() = 0;
    virtual void terminateServerSend() = 0;
    virtual void setMaxAllowedReceiveOffset(size_t) = 0;
    virtual size_t getMaxAllowedSendOffset() const = 0;

    virtual std::vector<uint8_t> const& getReceivedData() const = 0;
    virtual bool isRangeReceived(size_t from, size_t to) const = 0;
    virtual bool isNothingInRangeReceived(size_t from, size_t to) const = 0;
    bool isReceivedExactlyUpTo(size_t to) const { return isRangeReceived(0, to) && isNothingInRangeReceived(to, 0xffffffff); }
    virtual bool isReceiveComplete() const = 0;
    virtual void sendData(uint8_t const* pData, size_t szData) = 0;
    void sendData(std::vector<uint8_t> const data) { sendData(data.data(), data.size()); }
    virtual void markSendComplete() = 0;
};
struct QUIBServer {
    virtual ~QUIBServer() = default;
    virtual std::array<uint8_t, 160> const& getPeerConnectionId() const = 0;
    virtual QUIBStream* newStream(bool bidir) = 0;
    virtual std::vector<QUIBStream*> const& streams() const = 0;
    QUIBStream* assertStream(size_t i, size_t n) const {
        auto const& streams = this->streams();
        assertEquals("You opened stream(s)", streams.size(), n);
        return streams[i-1];
    }
    QUIBStream* assertStream(size_t i=1) const { return assertStream(i,i); }
    virtual void receivePacket(QUIBPacket const&) = 0;
    virtual std::vector<std::unique_ptr<QUIBPacket>> sendPackets() = 0;
    virtual void considerYourPacketLost(QUIBPacket const&) = 0;
    void considerYourPacketLost(std::vector<std::unique_ptr<QUIBPacket>> const& v) {
        for (auto const& p : v) considerYourPacketLost(*p);
    }
    virtual std::optional<uint8_t> getExitCodeIfClosed() const = 0;
    inline bool isClosed() { return getExitCodeIfClosed() != std::nullopt; }
    virtual std::set<uint32_t> const& getUnacknowledgedAckElicitingPacketNumbers() const = 0;
    
    virtual QUIBPacket decorateToPacket(std::unique_ptr<QUIBFrame>&& ptr) = 0;
    template <typename T, typename Init> QUIBPacket decorateToPacket(Init const& initialize) {
        auto ptr = std::make_unique<T>();
        initialize(ptr.get());
        return decorateToPacket(std::move(ptr));
    }
};
std::unique_ptr<QUIBServer> startServer(QUIBPacket const& initial);
}
