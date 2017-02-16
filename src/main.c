#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

void *Func_p_time(void *data)
{
	time_t t;
	struct tm *tm;
	while(1)
	{
		time(&t);
		tm = localtime(&t);
		printf("%.2d-%.2d-%.4d %.2d:%.2d:%.2d\n", 
				tm->tm_year+1900, 
				tm->tm_mon+1, 
				tm->tm_mday, 
				tm->tm_hour,
				tm->tm_min,
				tm->tm_sec
				);
		sleep(1);
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	printf("Module: Testing!\n");
	pthread_t pid;
	printf("pthread_create() Result: %d\n", pthread_create(&pid, NULL, Func_p_time, NULL));
	int index;
	for(index = 0; index < 4; index++)
	{
		sleep(index);
	}
	printf("pthread_cancel() Result: %d\n", pthread_cancel(pid));
	printf("pthread_join() Result: %d\n", pthread_join(pid, NULL));
	return 0;
}
