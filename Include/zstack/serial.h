#ifndef SERIAL_H
#define SERIAL_H

extern unsigned int serial_open(unsigned char id);
extern unsigned int serial_read(unsigned int fd, unsigned char* buffer, unsigned int length, int timeout);
extern unsigned int serial_write(unsigned int fd, unsigned char* buffer, unsigned int length);
extern void serial_port_list(void);

#endif
