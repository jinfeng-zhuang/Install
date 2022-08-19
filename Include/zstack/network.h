#ifndef ZSTACK_NETWORK_H
#define ZSTACK_NETWORK_H

#include "types.h"

// continuously transfer
extern int net_connect(const char* host_name, u16 port, u32 msec);
extern int net_transfer(const char *name, void* tx, void* rx);
extern int net_disconnect(void);

extern int network_init(void);
extern void network_deinit(void);
extern int tcp_open(const char* hostname, u16 port);
extern int tcp_close(int fd);
extern int tcp_send(int fd, u8* buf, s32 len, s32 flags);
extern int tcp_recv(int fd, u8* buf, s32 len, s32 flags);

extern void tcp_server_create(int port, int (*client)(void *));
extern int tcp_client_create(const char *hostname, u16 port);

#endif