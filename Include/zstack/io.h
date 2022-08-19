#ifndef ZSTACK_IO_H
#define ZSTACK_IO_H

#include "types.h"

extern u64 file_size(const char* filename);
extern u32 file_load(const char* filename, u64 offset, u8 *buffer, u32 length);
extern u32 file_save(const char* filename, u8* buffer, u32 length);
extern u32 file_append(const char* filename, u8* buffer, u32 length);
extern u8* file_load_simple(const char* filename, u64 offset, u32* length);

/*
 * length <= window
 * return processed bytes
 */
typedef unsigned int (*file_load_callback)(const size_t location, unsigned char* buffer, unsigned int length);

/*
 * return if reach EOS or error occurs
 */
extern int file_load_by_window(const char* filename, const int window, file_load_callback cb);

extern void serial_port_list(void);

extern u32 serial_open(u8 id);
extern u32 serial_read(u32 fd, u8* buffer, u32 length, int timeout);
extern u32 serial_write(u32 fd, u8* buffer, u32 length);

#endif
