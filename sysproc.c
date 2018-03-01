#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "pstat.h"

extern int systemCallCount;
extern struct pstat pinfo;

int
sys_getSysCallInfo(void)
{
  return systemCallCount;
}

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}


//My implementation of sys_sbrk
/*
This implementation should only increment the proc->sz by n bytes & return the old size
Should NOT allocate memory, deleting growproc, but still need to increase process' size
*/

int
sys_sbrk(void)
{
	int addr;
	int n;

	if(argint(0,&n) < 0)
		return -1;
	addr = myproc()->sz;

	//if(growproc(n)<0)
	//	return -1;
	myproc()->sz += n;
	
	return addr;
}

//Original implementation of sys_sbrk
/*
int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}
*/


int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
/*  Assignment 3 additions.
	Two system calls
*/
int
sys_settickets(void)
{
	return 0;
}

int
sys_getpinfo(struct pstat *p)
{
	p = &pinfo;
	return 0;
}

//End of assignment 3 additions
