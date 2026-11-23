#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char savedText[10][100];

int main(int argc, char *argv[])
{
	int fd;
	int total = 0;
	int col = 0;
	int i;
	int a;
	int b = 0;
	char buf, in[100], *t;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) < 0) {
		printf("File read fail\n");
		return 1;
	}
	while (read(fd, &buf, 1) > 0) {
		if (buf == '\n') total++, col = 0;
		else savedText[total][col++] = buf;
	}
	if (col) total++;
	close(fd);

	printf("File read success\n");
	printf("Total Line : %d\n", total);
	printf("You can choose 1 ~ %d Line\n", total);
	printf("Pls 'Enter' the line to select : ");

	scanf("%s", in);
	if (in[0] == '*') {
		for (i = 0; i < total; i++) { 
			printf("%s\n", savedText[i]);
		}
	} else if (strchr(in, '-')) {
		scanf(in, "%d-%d", &a, &b);
		for (i = a; i <= b; i++) {
			printf("%s\n", savedText[i - 1]);
		}
	} else {
		for (t = strtok(in, ","); t; t = strtok(NULL, ",")) {
			printf("%s\n", savedText[atoi(t) - 1]);
		}
	}
	return 0;
}

