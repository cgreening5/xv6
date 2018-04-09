#include "types.h"
#include "user.h"
#include "threads.h"
#include "param.h"
#include "mmu.h"

int thread_create(void (*start_routine)(void *), void * arg)
{
  void * stack = malloc(PGSIZE * 2);
  stack = stack + PGSIZE - ((int)stack % PGSIZE);
  if (stack == 0)
    return -1;

  return clone(start_routine, arg, (void*) stack);
}

int thread_join()
{
  void * stack;
  int result;
  if ((result = join(&stack)) > 0)
  {
    free(stack);
  }

  return result;
}

