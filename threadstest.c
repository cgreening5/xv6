#include "types.h"
#include "user.h"
#include "threads.h"

void test(void * params)
{
	for(int i = 0; i < 5; i++)
	{
		printf(1, "Hi from %d\n",(int)params);
	}
  exit();
}

int main()
{
	int t1 = 12;
	int t2 = 7;
  printf(1, "Creating thread %d\n", thread_create(&test, (void*)&t1));
  printf(1, "Creating thread %d\n", thread_create(&test, (void*)&t2));
  printf(1, "Joining threads.\n");
  //printf(1, "Cleaned up %d.\n", pid);
  //printf(1, "Cleaned up %d.\n", pid);
  printf(1, "Done.\n");
  exit();
}
