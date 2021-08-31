#ifndef ZSTACK_YUV_H
#define ZSTACK_YUV_H

enum YUVFormat {
    YUVFormat_NotSupport = -1,

    // 420P
    YU12,
    YV12,

    // 420SP
    NV12,
    NV21,

    // 422P
    YU16,
    YV16,

    // 422SP
    NV16,
    NV61,

    // 444
};

struct YUV_Wrapper {
    unsigned int (*FrameSize)(int width, int height);
    unsigned short (*GetU)(unsigned char* buffer, int width, int height, int x, int y);
    unsigned short (*GetV)(unsigned char* buffer, int width, int height, int x, int y);
    void (*SetU)(unsigned char* buffer, int width, int height, int x, int y, unsigned short u);
    void (*SetV)(unsigned char* buffer, int width, int height, int x, int y, unsigned short v);
};

extern struct YUV_Wrapper* YUV_Wrapper_Init(enum YUVFormat);

extern enum YUVFormat YUVFormat_Value(const char *s);

#endif
