#include <stdio.h>
#include <string.h>

int n = 0;
int line = 1;
int start = 1;

void cat(FILE *fp)
{
	int c;
	while ((c = getc(fp)) != EOF)
	{
		if (n && start) {
	 		printf("%6d\t", line++), start =0;
		}
		putc(c,stdout);
		if (c == '\n') {
			start = 1;
		}
	}
}

int main(int argc, char *argv[])
{
	FILE *fp;
	int c, i, n = 0, line = 1, start = 1;

	for (i = 1; i < argc; i++)
		if (strcmp(argv[i], "-n") == 0) n = 1;

	for (i = 1; i < argc || i == 1; i++)
	{
		if (argc < 2) fp = stdin;
		else if (strcmp(argv[i], "-n") == 0) continue;
		else if ((fp = fopen(argv[i], "r")) == NULL) continue;

		while ((c = getc(fp)) != EOF)
		{
			if (n && start) printf("%6d\t", line++), start = 0;
			putc(c, stdout);
			if (c == '\n') start = 1;
		}
		if (fp != stdin) fclose(fp);
	}
	return 0;
}

