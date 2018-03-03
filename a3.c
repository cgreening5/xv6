#include "types.h"
#include "user.h"
#define stdout 1

int  makebatchprocess()
{
  int pid = fork();
  if (pid)
  {
    while(1);
  }

  return pid;
}

int makeinteractiveprocess()
{
  int pid = fork();
  if (pid)
  {
    while (1)
      sleep(1);
  }

  return pid;
}

int main()
{
  int pid1 = makebatchprocess();
  int pid2 = makeinteractiveprocess();
  kill(pid1);
  kill(pid2);
  exit();
}
