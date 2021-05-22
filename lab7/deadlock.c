#include <stdio.h>
#ifndef __USE_GNU
#define __USE_GNU   
#endif  
#include <unistd.h>
#include <sched.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>

int trans_id = 0;
int balance1 = 100000000;
int balance2 = 100000000;

pthread_mutex_t lock1;
pthread_mutex_t lock2;

void *runner1(void *param); /* threads call this function */
void *runner2(void *param); /* threads call this function */

int main(int argc, char *argv[])
{
	int i;

	pthread_t tid1, tid2; /* the thread identifier */
	pthread_attr_t attr; /* set of thread attributes */
	pthread_attr_init(&attr); /* get the default attributes */

	pthread_mutex_init(&lock1, NULL);
	pthread_mutex_init(&lock2, NULL);	

	pthread_create(&tid1, &attr, runner1, NULL); /* create the thread */
	pthread_create(&tid2, &attr, runner2, NULL); /* create the thread */

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

}

void *runner1(void *param)
{	
	cpu_set_t cpuSet;
	CPU_ZERO(&cpuSet);    //clear
        CPU_SET(0, &cpuSet);   //set core 0
	sched_setaffinity(0, sizeof(cpuSet), &cpuSet);
	
	while(1)
	{
			
		pthread_mutex_lock(&lock1);
		pthread_mutex_lock(&lock2);
		
		balance1 -= 1;
		balance2 += 1;
		trans_id += 1;
		printf("Transaction %d: Account 1 transfers 1 yuan to account 2.\n", trans_id);

		pthread_mutex_unlock(&lock2);
		pthread_mutex_unlock(&lock1);

		usleep(100000); //microseconds
	}


	pthread_exit(0);
}

void *runner2(void *param)
{	
	cpu_set_t cpuSet;
	CPU_ZERO(&cpuSet);    //clear
        CPU_SET(1, &cpuSet);   //set core 1
	sched_setaffinity(0, sizeof(cpuSet), &cpuSet);
	

	while(1)
	{
		pthread_mutex_lock(&lock2);
		pthread_mutex_lock(&lock1);
		
		balance2 -= 1;
		balance1 += 1;
		trans_id += 1;
		printf("Transaction %d: Account 2 transfers 1 yuan to account 1.\n", trans_id);

		pthread_mutex_unlock(&lock1);
		pthread_mutex_unlock(&lock2);

		usleep(100000); //microseconds
	}

	pthread_exit(0);
}
