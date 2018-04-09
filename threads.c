#include "types.h"
#include "user.h"
#include "threads.h"
#include "param.h"
#include "mmu.h"
#include "x86.h"

int lock_init(lock_t *lock)
{
	lock->locked = 0;
	return 0;
}

void lock_acquire(lock_t *lock)
{
	while(xchg(&lock->locked, 1) != 0);
		//SPIN.
}

void lock_release(lock_t *lock)
{
	xchg(&lock->locked, 0);
}

int thread_create(void (*start_routine)(void *), void * arg)
{
  void * stack = malloc(PGSIZE * 2);
  if (stack == 0)
    return -1;

  return clone(start_routine, arg, (void*) stack);
}

int thread_join()
{
  void * stack;
  int result = join(&stack);
  if (result > 0)
  {
    free(stack);
  }

  return result;
}

