#ifndef ZSTACK_THREAD_H
#define ZSTACK_THREAD_H

typedef void* sem_t;
typedef void* mutex_t;

extern int thread_create(int (*thread_entry)(void*), void* args);

extern mutex_t mutex_create(void);
extern void         mutex_lock(mutex_t mutex);
extern void         mutex_unlock(mutex_t mutex);

extern sem_t sem_create(int count);
extern int sem_wait(sem_t sem, unsigned int ms);
extern int sem_post(sem_t sem);

#endif
