#ifndef ZSTACK_TRACE_H
#define ZSTACK_TRACE_H

//===================================================================
// API
//===================================================================

// The common channels
// User can define custom channels
enum {
  TC_ERROR = 1 << 0,
  TC_WARN = 1 << 0,
  TC_INFO = 1 << 1,
  TC_DATA = 1 << 2,
  TC_EVENT = 1 << 3,
  TC_STACK = 1 << 4, // Enter/Exit Function
  TC_PARAM = 1 << 5, // Parameter Check
  TC_HERE = 1 << 6,  // Execute to here
  TC_7 = 1 << 7,
  TC_USER = TC_7,
  TC_8 = 1 << 8,
  TC_9 = 1 << 9,
  TC_10 = 1 << 10,
  TC_11 = 1 << 11,
  TC_12 = 1 << 12,
  TC_13 = 1 << 13,
  TC_14 = 1 << 14,
  TC_15 = 1 << 15,
  TC_16 = 1 << 16,
  TC_17 = 1 << 17,
  TC_29 = 1 << 29,
};

enum {
  TC_FORMAT_FILE = 1 << 0,  // Write this log to file
  TC_FORMAT_TIME = 1 << 1,  // Add time to this log
  TC_FORMAT_FUNC = 1 << 2,  // Add function & line to this log
  TC_FORMAT_FILE_ONLY = 1 << 3, // Write to log file, but can't print it out
};

// Combine
// hexdump:data,net:stack,net:data,custom:10 // equal to 1<<10
// all:data
// all:stack
// all:time
// If no time,func for the module, the raw data is printed, useful for hexdump
#define TRACE(chan, format, ...) \
  trace(TRACE_MODULE, chan, __FUNCTION__, __LINE__, format, ##__VA_ARGS__)

extern int trace_init(char* str);
extern int trace_register(struct log_module* m);

//===================================================================
// Internal
//===================================================================

#ifndef TRACE_MODULE
#define TRACE_MODULE (&tc_default)
#endif

struct trace_module {
  char* name;
  int channel; // 0->disable
  int format;
};

extern struct trace_module tc_default;

// End with "name = NULL"
extern struct trace_module *trace_modules[];

extern void trace(struct trace_module *module,
  int channel,
  const char* func,
  const int line,
  const char* format,
  ...);

#endif
