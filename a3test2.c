#include "types.h"
#include "user.h"
#include "pstat.h"

#define stdout 1

#define NUM_SAMPLES 10
#define SAMPLE_INTERVAL 100

int getproc(int numtickets)
{

}

int main()
{
  pstat ps;
  int pid1 = getbusywaiter();
  int pid2 = getsleeper();
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

  kill(pid1);
  wait();
  kill(pid2);
  wait();
  exit();
}
