#include "types.h"
#include "user.h"
#include "mmu.h"
#define stdout 1

#define PGSIZE 4096

int canaccesspageboundaries(char * ptr)
{
	int testvalue = 0xDEADBEEF;
	ptr -= (int) ptr % PGSIZE;
	printf(stdout, "%x-", (int) ptr);
	memmove(ptr, &testvalue, sizeof(int));
	if (testvalue != *(int *)ptr)
	{
		return 0;
	}
	ptr += PGSIZE - 1;
	printf(stdout, "%x\n", (int) ptr);
	memmove(ptr, &testvalue, sizeof(int));
	if (testvalue != *(int *)ptr)
	{
		return 0;
	}
	return 1;
}

void test(int result)
{
	if (result)
	{
		printf(stdout, "Success.\n");
	}
	else
	{
		printf(stdout, "Failed.\n");
	}
}

int main()
{

	char * ptr = sbrk(0);
	printf(stdout, "Testing writing to page boundaries "
		       	"at initial process size.\n");
	test(canaccesspageboundaries(ptr));
	
	ptr = sbrk(PGSIZE + 1);

	printf(stdout, "Growing process from %d to %d bytes.\n", ptr, ptr + PGSIZE + 1);

	ptr += PGSIZE + 1; 
	printf(stdout, "Testing writing to page boundaries "
		       	"after growing process size.\n");
	test(canaccesspageboundaries(ptr));
	
	ptr += PGSIZE;
	printf(stdout, "Testing writing to page boundaries "
		       "past process size.\n");
	test(canaccesspageboundaries(ptr));
	exit();
}
