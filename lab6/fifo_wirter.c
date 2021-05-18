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
		printf("Opend for writing! %d\n", fd);
	getchar();

	memset(buf, 'A',10);
	memset(buf+10,'\0',1);
	write(fd,buf,11);

	close(fd);

	return 0;
}