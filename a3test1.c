#include "types.h"
#include "user.h"
#include "pstat.h"

#define stdout 1

#define NUM_SAMPLES 10
#define SAMPLE_INTERVAL 100

int getproc(int numtickets)
{
  int pid = fork();
  if (pid)
  {
    printf(stdout, "PID of proc with %d tickets: %d\n", numtickets, pid);
  }
  else
  {
    settickets(numtickets);
    while (1);
  }

  return pid;
}

int getbusywaiter()
{
  int pid = fork();
  if (pid)
  {
    printf(stdout, "PID of busywaiting process: %d\n", pid);
  }
  else
  {
    while(1);
  }

  return pid;
}

int getsleeper()
{
  int pid = fork();
  if (pid)
  {
    printf(stdout, "PID of sleeping process: %d\n", pid);
  }
  else
  {
    while (1)
    {
      sleep(1);
    }
  }

  return pid;
}

void printtestdata()
{
  pstat ps;
  for (int i = 0; i < NUM_SAMPLES; i++)
  {
    sleep(SAMPLE_INTERVAL);
    getpinfo(&ps);
    printf(stdout, "pid     hticks  lowticks\n");
    for (int i = 0; i < NPROC; i++)
    {
      if (ps.inuse[i])
      {
        char * formatstring = "%d       %d       %d\n";
        printf(stdout, formatstring, ps.pid[i], ps.hticks[i], ps.lticks[i]);
      }
    }
  }
  printf(stdout, "End of test.\n\n\n");
}

int main()
{

  int p1 = getbusywaiter();
  int p2 = getsleeper();
  printtestdata();

  kill(p1);
  wait();
  kill(p2);
  wait();
  
  p1 = getproc(10);
  p2 = getproc(1);
  int p3 = getproc(1);
  int p4 = getproc(1);
  int p5 = getproc(1);
  printtestdata();

  kill(p1);
  wait();
  kill(p2);
  wait();
  kill(p3);
  wait();
  kill(p4);
  wait();
  kill(p5);
  wait();
  exit();
}

