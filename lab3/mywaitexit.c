#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	pid_t new_pid;
	int status;

	new_pid = fork();
	if(new_pid == 0)
	{
		printf("this is child process: %d\n",getpid() );
		exit(-1);
	}
	else
	{
		printf("this is parent process: %d\n",getpid());
		wait(&status);
		printf("child exit status: %d\n",WEXITSTATUS(status));
	}


	return 0;
}