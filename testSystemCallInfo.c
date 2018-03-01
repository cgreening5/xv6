#include "types.h"
#include "stat.h"
#include "user.h"

extern int getSysCallInfo(void);

void testSysCallInfo()
{
	printf(1,"Number of system calls: %d\n", getSysCallInfo());
}

int main(void)
{
	testSysCallInfo();
	exit();
}
