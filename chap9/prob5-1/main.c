#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char*argv[])
{
	int fd,ststus;
	fd = open(argv[1], O_CREAT|O_TRUNC|O_WRONLY,0600);
	dup2(fd,1);
	close(fd);
	printf("Hello stdot !\n");
	fprintf(stderr," Hello stderr !\n");
}
