#ifndef ZSTACK_LOG_H
#define ZSTACK_LOG_H

#ifndef LOG_MODULE
#define LOG_MODULE __FUNCTION__
#endif

#ifndef info
#define info(argv, ...) _log(LOG_MODULE, 0, argv, ##__VA_ARGS__)
#endif

#ifndef warn
#define warn(argv, ...) _log(LOG_MODULE, 1, argv, ##__VA_ARGS__)
#endif

#define TRACE warn("%s %d\n", __FUNCTION__, __LINE__)

extern void log_init(const char *config);
extern int _log(const char *module, int level, const char *fmt, ...);

#endif
