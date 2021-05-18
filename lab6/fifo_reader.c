#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char buf[1024];

	int fd = open("myfifo",O_RDONLY);

	if(fd == -1)
		printf("Open error\n");
	else
		printf("Open for reading!%d\n", fd);
	read(fd,buf,1024);
	printf("String read from file[%d] is: %s\n", fd,buf);




	close(fd);

	return 0;
}