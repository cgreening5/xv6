#include "types.h"
#include "user.h"

void test(void * params)
{
  while (1)
    printf(1, "Hi\n");
  exit();
}

int main()
{
  void * stack = malloc(1024);
  stack += 512 - 512 % (int)stack;
  printf(1, "%d\n", clone(test, &stack, 0));
  while(1);
  exit();
}
