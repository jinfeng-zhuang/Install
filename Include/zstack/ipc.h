#ifndef ZSTACK_IPC_H
#define ZSTACK_IPC_H

extern int thread_create(int (*thread_entry)(void*), void* args);

extern unsigned int mutex_create(void);
extern void         mutex_lock(unsigned int mutex);
extern void         mutex_unlock(unsigned int mutex);

#endif