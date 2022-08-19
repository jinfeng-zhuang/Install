#ifndef ZSTACK_BIT_H
#define ZSTACK_BIT_H

#define BITVAL(buffer, bitpos) ((buffer[bitpos >> 3] & (1 << (7 - (bitpos & 0x7)))) ? 1 : 0)

#endif
