#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>
void *runnerSend(void *para);
void *runnerReceive(void *para);
bool threadStat = true;
int main(int argc, char const *argv[])
{
	mkfifo("./A2B",0644);
	mkfifo("./B2A",0644);
	int fdA2B = open("A2B",O_RDONLY);
	int fdB2A = open("B2A",O_WRONLY);
	if(fdA2B == -1 || fdA2B == -1)
		printf("Open error\n");
	else
	{
		printf("Start Connecting...\n");
		pthread_t tid1, tid2;
		pthread_attr_t attr1,attr2;
		pthread_attr_init(&attr1);
		pthread_attr_init(&attr2);
		printf("Terminal B Connect success!\n============================================================\n");
		pthread_create(&tid1,&attr1,runnerSend,&fdB2A);
		pthread_create(&tid2,&attr2,runnerReceive,&fdA2B);
		if(pthread_join(tid2,NULL) == 0 || pthread_join(tid1,NULL) == 0);
	}
	close(fdA2B);
	close(fdB2A);
	return 0;
}
void *runnerSend(void *para)
{	
	int fd = *(int *)para;
	char buf_send[1024];
	char* c88 = "88\n\0";
	while(threadStat)
	{	
		printf("\b\b\b\b\b\b");
		printf("[B]:> ");
		fgets(buf_send,1024,stdin);
		write(fd,buf_send,1024);
		if(strcmp(buf_send,c88) == 0)
			break;
	}
	threadStat = false;
	pthread_exit(NULL);
}
void *runnerReceive(void *para)
{	
	int fd = *(int *)para;
	char buf_receive[1024];
	char* c88 = "88\n\0";
	while(threadStat)
	{
		if(read(fd,buf_receive,1024) != 0)
		{	
			printf("\b\b\b\b\b\b");
			printf("[A]:> %s", buf_receive);
			if(strcmp(buf_receive,c88) == 0)
				break;
			printf("[B]:> ");
			fflush(stdout);
		}	
	}
	threadStat = false;
	pthread_exit(NULL);
}