#include "quib.h"
#include "framework/udp.h"

struct quib_connection {};
struct quib_stream {};

void quib_tick() {
    // TODO: implement this
}

quib_status quib_connect(quib_connection** pcHandle, ip_address addr, udp_port port) {
    // TODO: remove this line
    (void)pcHandle; (void)addr; (void)port;
    // TODO: implement this
    return NOT_YET_IMPLEMENTED;
}

bool quib_is_connected(quib_connection const* cHandle) {
    // TODO: remove this line
    (void)cHandle;
    // TODO: implement this
    return false;
}

void quib_close_connection(quib_connection* cHandle) {
    // TODO: remove this line
    (void)cHandle;
    // TODO: implement this
}

void quib_discard_connection(quib_connection* cHandle) {
    // TODO: remove this line
    (void)cHandle;
    // TODO: implement this
}

quib_status quib_new_stream(quib_connection* cHandle, quib_stream** psHandle, bool canReceive) {
    // TODO: remove this line
    (void)cHandle; (void)psHandle; (void)canReceive;
    // TODO: implement this
    return NOT_YET_IMPLEMENTED;
}

quib_status quib_accept_stream(quib_connection* cHandle, quib_stream** psHandle) {
    // TODO: remove this line
    (void)cHandle; (void)psHandle;
    // TODO: implement this
    return NOT_YET_IMPLEMENTED;
}

void quib_discard_stream(quib_stream* sHandle) {
    // TODO: remove this line
    (void)sHandle;
    // TODO: implement this
}

quib_status quib_send_data(quib_stream* sHandle, uint8_t const* pData, size_t szData, bool isFinal) {
    // TODO: remove this line
    (void) sHandle; (void)pData; (void)szData; (void)isFinal;
    // TODO: implement this
    return NOT_YET_IMPLEMENTED;
}

quib_status quib_receive_data(quib_stream* sHandle, uint8_t* pBuf, size_t szBuf, size_t* pNumReceived, bool* pIsFinal) {
    // TODO: remove this line
    (void)sHandle; (void)pBuf; (void)szBuf; (void)pNumReceived; (void)pIsFinal;
    // TODO: implement this
    return NOT_YET_IMPLEMENTED;
}
