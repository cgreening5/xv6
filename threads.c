#include "types.h"
#include "user.h"
#include "threads.h"
#include "param.h"
#include "mmu.h"
#include "x86.h"


static lock_t lock = {
  .locked = 0
};


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
	lock_acquire(&lock);
	//Critical section
	void * stack = malloc(PGSIZE * 2);
	lock_release(&lock);

	if (stack == 0)
		return -1;
  return clone(start_routine, arg, (void*) stack);
}

int thread_join()
{
  void * stack;
  int result;
	
	lock_acquire(&lock);
	if ((result = join(&stack)) > 0)
	{
		//Critical section	
		free(stack);
	}
	lock_release(&lock);

  return result;
}

