#ifndef ZSTACK_MISC_H
#define ZSTACK_MISC_H

#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#include "types.h"

/**************************************************************************************************
 *                                              Macros
 *************************************************************************************************/

#ifndef _WIN32
#define _fseeki64 fseek
#define _ftelli64 ftell
#endif

#define BITGET(RegValue, StartBit, Bits) (((RegValue) >> (StartBit)) & ((0x1 << (Bits)) - 1))

#define FILE_PATH_MAX   (FILENAME_MAX)
#define IP_LENGTH       (16)

#ifndef PI
#define PI (3.141592653589793)
#endif

#ifndef _WIN32
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) > (b)) ? (b) : (a))
#endif
#else
#include <stdlib.h>
#endif

#ifndef TRUE
#define TRUE    1
#endif

#ifndef FALSE
#define FALSE   0
#endif

#define SIZE_1KB	(1<<10)
#define SIZE_1MB	(1<<20)
#define SIZE_1GB	(1<<30)

/**************************************************************************************************
 *                                              Structures
 *************************************************************************************************/

struct application;

/**************************************************************************************************
 *                                              Variables
 *************************************************************************************************/

extern const char *version;
extern const char *usage;

/**************************************************************************************************
 *                                              Functions
 *************************************************************************************************/

enum {
	HEXDUMP_RAW = 0,
	HEXDUMP_ADDR = 1<<0,
	HEXDUMP_ASCII = 1<<1,
};

extern int hexdump(void* buffer, unsigned int length, unsigned int flags);

extern void print_usage(void);
extern int param_parser(int argc, char *argv[], struct application *app);

extern long png_to_bgra(const char* path, int* w, int* h, unsigned char** bgra);

extern int bmp_save(const char* filename, unsigned char* rgb, int w, int h);

extern int is_printable(unsigned char c);

extern u64 BE_read_u64(u8* buffer);
extern u32 BE_read_u32(u8* buffer);
extern u16 BE_read_u16(u8* buffer);
extern u8 BE_read_u8(u8* buffer);

extern u16 crc16(u8 *buffer, u32 length);

extern unsigned int errno_get(void);

extern unsigned int search_keyword(
  unsigned char* buffer,
  unsigned int length,
  unsigned int* offset,
  unsigned char* kw,
  unsigned int kwlen);

#endif
