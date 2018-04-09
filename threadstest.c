#include "types.h"
#include "user.h"
#include "threads.h"

//lock_t * lock;

void test(void * params)
{	
	for(int i = 0; i < 5; i++)
	{
		//lock_acquire(lock);
		printf(1, "Hi from %d\n",(int)params);
		//lock_release(lock);
	}
}

int main()
{
	int t1 = 12;
	int t2 = 7;
	//lock = malloc(sizeof(lock_t));
	//lock_init(lock);
	thread_create(&test, (void*)t1);
	thread_create(&test, (void*)t2);

	//thread_join();
	//thread_join();
	//free(lock);
  printf(1, "Hello\n");
  exit();
}
