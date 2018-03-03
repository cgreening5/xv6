#include "types.h"
#include "user.h"
#define stdout 1

void makebatchprocess()
{
  int pid = fork();
  printf(stdout, "%d\n", pid);
}

int main()
{
  makebatchprocess();
}
