#ifndef ZSTACK_HEXDUMP_H
#define ZSTACK_HEXDUMP_H

enum {
	HEXDUMP_RAW = 0,
	HEXDUMP_ADDR = 1<<0,
	HEXDUMP_ASCII = 1<<1,
};

extern int hexdump(void* buffer, unsigned int length, unsigned int flags);

#endif
