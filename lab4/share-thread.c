#include <pthread.h>
#include <stdio.h>

int sum = 0;
void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[])
{

	pthread_t tid1,tid2; /* the thread identifier */
	pthread_attr_t attr; /* set of thread attributes */

	/*set the default attributes */
	pthread_attr_init(&attr);

	printf("sum is: %d\n",sum );

	/* create the thread */
	pthread_create(&tid1, &attr, runner, NULL);
	pthread_create(&tid2, &attr, runner, NULL);
	printf("This is in parent thread!\n");

	pthread_join(tid1, NULL); //wait for the created thread to terminate
	pthread_join(tid2, NULL); //wait for the created thread to terminate

}
void *runner(void *param)
{
	
	printf("in,runner, the sum is: %d\n",++sum);
	
	while(1);
	
	pthread_exit(NULL); //exit
}
