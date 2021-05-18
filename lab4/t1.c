#include <pthread.h>
#include <stdio.h>
void *runner(void *param);
struct pair
{
	int x;
	int y;
};
int main(int argc, char const *argv[])
{
	//int arg[2] = {1357,2468};
	int x = 1357;
	int y = 2468;
	struct pair arg;
	arg.x = x;
	arg.y = y;
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,runner,&arg);

	printf("This is in parent thread\n");
	pthread_join(tid,NULL);
	return 0;
}
void *runner(void *param)
{
	//printf("The sum of two args is: %d\n", *(int *)param+*((int *)param+1));
	printf("The sum of two args is: %d\n", ((struct pair *)param)->x+((struct pair *)param)->y);
	pthread_exit(NULL);
}