#include "types.h"
#include "user.h"
#include "threads.h"

void test(void * params)
{
	for(int i = 0; i < 5; i++)
	{
		printf(1, "Hi from %d\n",(int)params);
	}

  while(1);
}

int main()
{
	int t1 = 12;
	int t2 = 7;
  thread_create(&test, (void*)&t1);
  thread_create(&test, (void*)&t2);

	//thread_join();
	//thread_join();
  printf(1, "Hello\n");
  while(1);
  exit();
}
