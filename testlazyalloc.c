#include "types.h"
#include "user.h"
#include "mmu.h"

#define stdout 1

int main()
{
	for (int i = 0; i < 8; i++)
	{
		void * pointer = sbrk(PGSIZE + 1);
		printf(stdout, "Memory allocated: %x\n", pointer);
	}
	exit();
}
