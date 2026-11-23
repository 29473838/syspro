#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char savedText[100][100];

int main(int argc, char *argv[])
{
	int fd, total = 0, col = 0, i;
	char buf;

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

	for (i = total - 1; i >= 0; i--)
		printf("%s\n", savedText[i]);
	return 0;
}
