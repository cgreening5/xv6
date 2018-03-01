#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

//extern struct pstat ps;

int main()
{
	int i = 0;
	struct pstat *ps = malloc(sizeof(struct pstat*));
	int success = -1;	
	printf(1,"ps addr:%x\n",ps);
	success = getpinfo(ps);
	printf(1,"ps addr:%x\n",ps);
	success++;
	
	for(i = 0; i < NPROC; i++)
	{
		printf(1,"inuse: %d\n",ps->);		
	}

	exit();
}
