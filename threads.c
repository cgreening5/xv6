#include "types.h"
#include "user.h"
#include "threads.h"
#include "mmu.h"

int thread_create(void (*start_routine)(void *), void * arg)
{
  int oldsize = (int) sbrk(0);
  int stack;
  if (oldsize % PGSIZE == 0)
    stack = oldsize;
  else
    stack = oldsize + PGSIZE - oldsize % PGSIZE;
  
  if (sbrk(stack - oldsize + PGSIZE) < 0)
    return -1;
  return clone(start_routine, (void*) stack, arg);
}
