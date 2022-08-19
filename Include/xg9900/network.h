#ifndef XG9900_NETWORK_H
#define XG9900_NETWORK_H

extern int xg9900_basic_send(unsigned char *buffer, unsigned int length);
extern int xg9900_basic_recv(unsigned char *buffer, unsigned int length);

extern int xg9900_send_one_package(unsigned char *payload, unsigned int length);
extern int xg9900_recv_one_package(unsigned char *payload, unsigned int length);

// if callback if NULL, it's a tx channel, otherwise it's a rx channel
extern int xg9900_channel_create(int (*callback)(u8 *buffer, u32 length));
extern int xg9900_channel_send_reliable(unsigned char chan, unsigned char *payload, unsigned int length);

#endif
