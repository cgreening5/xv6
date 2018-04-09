#include "types.h"
#include "user.h"
#include "threads.h"

void test(void * params)
{
  while (1)
    printf(1, "Hi\n");
  exit();
}

int main()
{
  thread_create(test, 0);
  while(1)
    printf(1, "Hello\n");
  exit();
}
