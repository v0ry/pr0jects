#pragma once

#include <array>
#include <cstdint>
#include "framework/udp.h"

enum quib_status : uint8_t {
    NO_ERROR = 0,
    NOT_YET_IMPLEMENTED,
    ERR_BUFFER_EXCEEDED,
    ERR_CONNECTION_TIMEOUT,
    ERR_CONNECTION_CLOSED,
    ERR_READ_ONLY_STREAM,
    ERR_WRITE_ONLY_STREAM,
    ERR_STREAM_RESET,
    ERR_STREAM_WRITE_CLOSED,
    
    // You can use this as a catch-all for any other problems you encounter; we don't mandate its use for anything in particular
    GENERIC_FAILURE
};

inline char const* quib_status_str(quib_status v) {
    switch (v) {
        case NO_ERROR: return "The operation succeeded";
        case NOT_YET_IMPLEMENTED: return "This feature is not implemented yet";
        case ERR_BUFFER_EXCEEDED: return "Internal buffer is insufficient";
        case ERR_CONNECTION_TIMEOUT: return "Connection timed out";
        case ERR_CONNECTION_CLOSED: return "Connection is closed";
        case ERR_READ_ONLY_STREAM: return "Stream is read only";
        case ERR_WRITE_ONLY_STREAM: return "Stream is write only";
        case ERR_STREAM_RESET: return "The stream has been reset";
        case ERR_STREAM_WRITE_CLOSED: return "Stream is closed for writing";
        case GENERIC_FAILURE: return "Generic failure";
        default: return "Unknown or invalid error";
    }
}

struct quib_connection;
struct quib_stream;

/** this function is called regularly by the framework. you should use it to perform processing, send and receive packets.
 *   you must not send or receive packets outside of this function. */
void quib_tick();

/** this function should open a quib connection to the specified host/port. */
quib_status quib_connect(quib_connection** pcHandle, ip_address addr, udp_port port);

/** this function returns true if, and only if, the connection's handshake has completed successfully, and the connection is not closed. */
bool quib_is_connected(quib_connection const* cHandle);

/** closes the quib connection. the connection handle remains valid.
 *   closing the connection also implicitly resets any still-open streams. stream handles remain valid. */
void quib_close_connection(quib_connection* cHandle);

/** discards the quib connection, invalidating the connection handle. it may no longer be used by the caller.
 *   any stream handles remain valid until they are discarded, but operations on them will fail with ERR_CONNECTION_CLOSED.
 *    if the connection is still open, closes it. */
void quib_discard_connection(quib_connection* cHandle);

/** this function should create a new data stream within the given connection. */
quib_status quib_new_stream(quib_connection* cHandle, quib_stream** psHandle, bool canReceive);

/** if the peer has initiated a new stream, this function sets (*psHandle) to a handle for it. if not, it sets (*psHandle) to nullptr. */
quib_status quib_accept_stream(quib_connection* cHandle, quib_stream** psHandle);

/** discards the stream, invalidating the stream handle. it may no longer be used by the caller. the function returns immediately.
 *   if the stream's sending part is still open, it is reset. if its receiving part is open, it is stopped. */
void quib_discard_stream(quib_stream* sHandle);

/** this function enqueues data for sending on this stream. */
quib_status quib_send_data(quib_stream* sHandle, uint8_t const* pData, size_t szData, bool isFinal);

/** this function receives at most the specified number of bytes on the stream.
 *   the number of bytes actually written to pBuf is stored to (*pNumReceived).
 *   (*pIsFinal) is set to true if the stream is complete with the read data, false otherwise. */
quib_status quib_receive_data(quib_stream* sHandle, uint8_t* pBuf, size_t szBuf, size_t* pNumReceived, bool* pIsFinal);
