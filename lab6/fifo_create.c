#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
	int res = mkfifo("./myfifo",0664);

	if(res == 0)
		printf("Named pipe created!\n");
	else if(res == -1)
		printf("Failed to create FIFO\n");
	else
		printf("Error\n");
	return 0;
}