#ifndef H264_SE_H
#define H264_SE_H

extern unsigned int se_read_u(struct bitstream *bitstream, unsigned int num);
extern int se_read_se(struct bitstream *bs);
extern unsigned int se_read_ue(struct bitstream *bitstream);

#endif
