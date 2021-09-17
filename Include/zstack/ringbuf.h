//
// if buffer is NULL, just update wp, rp
//

#ifndef ZSTACK_RINGBUF_H
#define ZSTACK_RINGBUF_H

#include "types.h"

struct ringbuffer {
	unsigned char *buffer;
	unsigned int length;
	unsigned int wp;
	unsigned int rp;
};

extern int ringbuf_init(struct ringbuffer *r, unsigned char *buffer, unsigned int length);

extern unsigned int ringbuf_put(struct ringbuffer *r, unsigned char *buffer, unsigned int length);
extern unsigned int ringbuf_get(struct ringbuffer *r, unsigned char *buffer, unsigned int length);

extern unsigned int ringbuf_datalen(struct ringbuffer *r);
extern float ringbuf_datalen_percent(struct ringbuffer *r);
extern unsigned int ringbuf_empty(struct ringbuffer *r);

#endif
