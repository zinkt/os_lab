#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	pid_t new_pid;

	new_pid = fork();

	if (new_pid == 0)
	{
		/* children */
		printf("it is children process\n");
		while(1);
	}
	else
	{
		//parent
		printf("it is parent process\n");
		while(1);
	}

	return 0;
}