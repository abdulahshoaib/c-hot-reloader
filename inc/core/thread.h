// thread init/join
#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>

typedef void (*TaskFunction)(void *);

typedef struct {
  TaskFunction function;
  void *arg;
} Task;

void thread_pool_init(void);
void thread_pool_submit(TaskFunction function, void *arg);
void thread_pool_destroy(void);

#endif // !THREAD_H
