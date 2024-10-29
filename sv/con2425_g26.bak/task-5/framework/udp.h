#include <cstdint>
#include <cstddef>
#include <array>

using ip_address = std::array<uint8_t, 4>;
using udp_port = uint16_t;

/* These functions are implemented by us, you can simply use them. */
struct udp_socket;
/* opens a socket that communicates with the specified peer. */
udp_socket* udp_open(ip_address peerAddr, udp_port peerPort);
/* send a datagram. */
void udp_send_datagram(udp_socket* handle, uint8_t const* pData, size_t szData);
/* receive a datagram if one is available. returns size of received payload. returns 0 if no datagram is available. stores payload in pBuf. */
size_t udp_receive_datagram(udp_socket* handle, uint8_t* pBuf, size_t szBuf);
/* closes a socket and frees associated resources */
void udp_close(udp_socket*);
