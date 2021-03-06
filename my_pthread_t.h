#ifndef MY_PTHREAD_H
#define MY_PTHREAD_H

#include <stdio.h>
#include <unistd.h>
#include <ucontext.h>

#include "common.h"

typedef struct {
	int attr;
} my_pthread_mutexattr_t;

//mutex
typedef struct {
	int mutex;
	const my_pthread_mutexattr_t* mutexattr_t;
} my_pthread_mutex_t;

//status of a thread
typedef enum {
	READY = 1,
	WAITING = 2,
	RUNNING = 3,
	FINISHED = 4
} STATE;

typedef struct{
	unsigned int tid;
	ucontext_t* context;
	long long last_start_time;
	STATE st;
	unsigned int priority;
	void* stack;
	void* retval;
} my_pthread_t;


//Functions of thread
void my_pthread_create(my_pthread_t* thread, pthread_attr_t* attr,void *(*function)(void*),void* arg);
int my_pthread_exit(void *value_ptr);
void my_pthread_yield();
int my_pthread_join(my_pthread_t thread,void **value_ptr);

//Functions of mutex
int my_pthread_mutex_init(my_pthread_mutex_t* mutex, const my_pthread_mutexattr_t* mutexattr);
int my_pthread_mutex_lock(my_pthread_mutex_t *mutex);
int my_pthread_mutex_unlock(my_pthread_mutex_t *mutex);
int my_pthread_mutex_destroy(my_pthread_mutex_t *mutex);


#endif
