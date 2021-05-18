#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char buf[1024];
	int fd = open("myfifo",O_WRONLY);
	if(fd == -1)
		printf("Open error\n");
	else
		printf("Opened for writing! %d\n", fd);
	
	while(fgets(buf,1024,stdin) != NULL)
	{
		write(fd,buf,1024);
	}
	close(fd);
	return 0;
}