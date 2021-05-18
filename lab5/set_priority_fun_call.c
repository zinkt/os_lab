#include <stdio.h>
#ifndef __USE_GNU //double underscore
#define __USE_GNU //double underscore  
#endif
#include <unistd.h>        
#include <sched.h>
#include <sys/resource.h>  

/*
**************sudo to execute this program*******************
*/

int main(int argc, char *argv[])
{
	int i = 0;
	
	cpu_set_t curr_set;
	
	CPU_ZERO(&curr_set);    //clear cpu settings
        CPU_SET(0, &curr_set);   //set core 0 (exclusively)
	sched_setaffinity(0, sizeof(curr_set), &curr_set); //0 represent current process	
						       //affinity will be inherted by child process
	
	pid_t pid = fork();
	
	if(pid == 0)//child
	{
		
		// [-20, 19]: from high to low priorities
		printf("child's old pri: %d\n", getpriority(PRIO_PROCESS, 0)); //get priority
										//0 means current process
		setpriority(PRIO_PROCESS, 0, 19); //set priority
							//PRIO_PROCESS means to set the priority of a process, 
							//rather than a group of processes
							//0 means current process
		printf("child's new pri: %d\n", getpriority(PRIO_PROCESS, 0)); //0 means current process
		
		sleep(5); //wait for some time so that the users can see the old and new priorites of child
		
		while(1)
		{
			printf("child: %d\n", i);
			i++;
		}
	}
	else //parent
	{
		sleep(5);
		while(1)
		{
			printf("parent: %d\n", i);
			i++;
		}
	}
		
	return 0;
}


