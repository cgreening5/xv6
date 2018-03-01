#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"

typedef struct pstat {
	int inuse[NPROC]; //whether this slot of the process table is in use. 0 or 1
	int pid[NPROC]; //PID of each process
	int hticks[NPROC]; // Number of ticks each process has accumulated at HIGH priority
	int lticks[NPROC]; // Number of ticks each process has accumulated at LOW priority
}pstat;

#endif // _PSTAT_H_
