// thread wrappers and mutex helpers
#ifndef THREAD_UTILS_H
#define THREAD_UTILS_H

#include <semaphore.h>

typedef struct {
  sem_t sem;
} Semaphore;

void sem_init_s(Semaphore *s, int initital_value);
void sem_wait_s(Semaphore *s);
void sem_post_s(Semaphore *s);
void sem_destroy_s(Semaphore *s);
void ms_sleep(int millisecond);

#endif // !THREAD_UTILS_H
