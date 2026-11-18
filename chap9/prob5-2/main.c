#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>


int main(int argc, char* argv[])
{
	int child, pid, fd, status;

	pid = fork();
	
	if (pid == 0) {
		fd = open(argv[1],O_CREAT|
			O_TRUNC| O_WRONLY, 0600);
		dup2(fd, 1);
		close(fd);
		execvp(argv[2], &argv[2]);
		fprintf(stderr, "Hello stdout ! \n");
	} else {
		child = wait(&status);
		printf("[%d] child process %d end \n", 
		getpid(), child);
	}
}
