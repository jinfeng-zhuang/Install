#ifndef ZSTACK_TYPES_H
#define ZSTACK_TYPES_H

#define u8  unsigned char
#define s8  char
#define u16 unsigned short
#define s16 short
#define u32 unsigned int
#define s32 int
#define u64 unsigned long long
#define s64 long long
#define f32 float
#define f64 double

#ifndef NULL
#define NULL	((void *)0)
#endif

#define SIZE_1KB	(1<<10)
#define SIZE_1MB	(1<<20)
#define SIZE_1GB	(1<<30)

// 0 = OK
// -1 = ERROR
#ifndef RESULT
#define RESULT int
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

#endif
