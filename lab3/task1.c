#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	pid_t new_pid;
	int status;

	new_pid = fork();
	if(new_pid == 0)
	{
		printf("This is in child process: %d, now execute mysum...\n",getpid());
		execl("./mysum", " ", "6", "8",NULL);
		//the rest will never be executed, as the child process has been replaced by mysum
		printf("This is the rest of the child process\n");
		exit(255);
	}
	else
	{
		printf("This is parent process: %d, and it is going to wait...\n",getpid());
		wait(&status);
		printf("The exit status of the child process is: %d\n", WEXITSTATUS(status));
	}

	return 0;
}