#ifndef ZSTACK_BITSTREAM_H
#define ZSTACK_BITSTREAM_H

struct bitstream {
	unsigned char* buffer;
	unsigned int bitlen;
	unsigned int bitpos;
};

/*
 * Malloc internal, copy user data
 * return -1 if failed
 * return 0  if ok
 */
extern int bitstream_init(struct bitstream *bs, unsigned char *buf, unsigned int len);
extern int bitstream_deinit(struct bitstream* bs);

extern unsigned int bitstream_u(struct bitstream *bs, unsigned int bitlen);
extern unsigned int bitstream_show(struct bitstream* bs, unsigned int bitlen);

#endif
