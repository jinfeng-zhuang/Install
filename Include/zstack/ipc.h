#ifndef ZSTACK_IPC_H
#define ZSTACK_IPC_H

typedef int (*thread_entry)(void *);

extern int thread_create(thread_entry entry, void *args);

#endif
