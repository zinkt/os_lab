#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	if (argc != 3)
	{
		printf("please input two integers as arguments!\n");
	}
	else
	{
		printf("the sum is: %d\n", atoi(argv[1])+atoi(argv[2]));
	}
	exit(255);//used in task1
	return 0;
}