#ifndef VS_H
#define VS_H

#include <zstack/ringbuf.h>

#include "avmips.h"
#include "dbg.h"
#include "pman.h"
#include "sx.h"

extern enum sx_chip sx_chip_id;

extern int avmips_update_address(unsigned int* addr, int num);

extern char *avmips_get_version(void);
extern unsigned int avmips_get_log_wr(void);
extern char* avmips_get_log(unsigned int index);
extern int avmips_log_init(char* setting);

extern int vs_chip_id_get(void);

extern int avmips_get_malone_desc(struct ringbuffer* r);

extern unsigned int mpegdisp_luma_addr(unsigned char chan, unsigned char id);
extern unsigned int mpegdisp_chroma_addr(unsigned char chan, unsigned char id);
extern unsigned int mpegdisp_frameinfo_addr(unsigned char chan, unsigned char id);

extern int vs_dump_yuv(const char* filename, unsigned int luma, unsigned int chroma, int stride, int height);

extern int avmips_step(int on);

extern struct VideoFrameInfo* avmips_get_frameinfo(int channel);
extern triVideoSharedInfo_t* avmips_get_shareinfo(unsigned int channel);

extern void avmips_set_step_flag(int on);
extern int avmips_get_step_flag(void);

#endif
