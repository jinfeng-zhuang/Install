#ifndef ZSTACK_MP4_H
#define ZSTACK_MP4_H

#include "types.h"

struct MP4Box {
	u32 size;
	u32 type;
	u64 large_size;
};

extern RESULT mp4_box_scan(int depth, u8* buffer, u32 len);

extern int mp4_box_is_valid(u32 type);

#endif