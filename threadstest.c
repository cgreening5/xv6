#include "types.h"
#include "user.h"

void test(void * params)
{
  printf(1, "Hi\n");
  exit();
}

int main()
{
  clone(*test, malloc(512), 0);
  exit();
}
