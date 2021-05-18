#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int fd = open("myfifo",O_WRONLY);

	if(fd == -1)
		printf("Open error\n");
	else
		printf("Open for writing: the file descriptor: %d\n", fd);
	close(fd);

	return 0;
}