#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"
#include "pstat.h"

//extern struct pstat ps;

int main()
{
	int i = 0;
	pstat * ps = malloc(sizeof(pstat));
	int success = -1;
	

	//printf(1,"%x\n",ps);
	success = getpinfo(ps);
	printf(1,"%d\n",success);

	
	//success++;

	for(i = 0; i < NPROC; i++)
	{
		printf(1,"inuse: %d %d %d %d\n",ps->inuse[i],ps->pid[i],ps->hticks[i],ps->lticks[i]);		
		
	}

	exit();
}
