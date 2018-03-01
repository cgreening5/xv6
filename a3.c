#include "types.h"
#include "user.h"
#define stdout 1

void test(int result)
{
	if (result == 1)
	{
		printf(stdout, "Success\n.");
	}
	else
	{
		printf(stdout, "Failure.\n");
	}
}

void testNumTickets()
{
	test(!settickets(10));	
	test(settickets(-1) != 0);
}

int main()
{
	testNumTickets();
	exit();
}
