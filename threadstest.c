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
  void * stack = malloc(512);
  stack += 512;
  clone(*test, stack, 0);
  printf(1, "returned\n");
  while(1);
  exit();
}
