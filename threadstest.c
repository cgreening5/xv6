#include "types.h"
#include "user.h"
#include "threads.h"

static lock_t lock = {
  .locked = 0
};

void test(void * params)
{	
	for(int i = 0; i < 5; i++)
	{
		lock_acquire(&lock);
		printf(1, "Hi from %d\n",(int)params);
		lock_release(&lock);
	}
  exit();
}

int main()
{
  printf(1, "1\n");
	int t1 = 12;
	int t2 = 7;
	thread_create(&test, (void*)t1);
	thread_create(&test, (void*)t2);

  printf(1, "1\n");
	thread_join();
	thread_join();
  exit();
}
