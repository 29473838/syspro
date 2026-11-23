#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main (int argc, char *argv[])
{
	char **tr;
	char *ptr;
	extern char **environ;
	char *a;
	a = argv[2];
	printf("%s",a);
	if (argv[1]  == "-e") {
		if (argv[2] != "") {
			ptr = getenv(a);
			printf("%s = %s \n", a, ptr);
		} else {
			for (tr = environ; *tr != 0; tr++)
				printf("%s \n", *tr);
		}
	}
	
	if (argv[1]  == "-u") {
		printf("my Realistic User ID : %d(%s) \n", getuid(), getpwuid(getuid())-> pw_name);
		printf("my Valid User ID : %d(%s) \n", geteuid(), getpwuid(geteuid())-> pw_name);
	}

	if (argv[1]  == "-g") {
		printf("my Realistic Group ID : %d(%s) \n", getgid(), getgrgid(getgid())-> gr_name);
		printf("my Valid Group ID : %d(%s) \n", getegid(), getgrgid(getegid())-> gr_name);
	}

	if (argv[1] == "-i") {
		printf("my process number: [%d] \n", getpid());
	}

	if (argv[1] == "-p") {
		 printf("my parent  process number: [%d] \n", getppid());
	}
}
