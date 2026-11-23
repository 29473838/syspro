#include <stdio.h>


int main(int argc, char *argv[])
{
	FILE *src, *dst;
	char buf[1024];
	size_t n;

	if (argc != 3) {
		fprintf(stderr, "How to use: %s File1 File2\n", argv[0]);
		return 1;
	}
	if ((src = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Error Open File: %s\n", argv[1]);
		return 2;
	}
	if ((dst = fopen(argv[2], "ab")) == NULL) {
		fprintf(stderr, "Error Open File: %s\n", argv[2]);
		fclose(src);
		return 3;
	}

	while ((n = fread(buf, 1, sizeof(buf), src)) > 0)
		fwrite(buf, 1, n, dst);

	fclose(src);
	fclose(dst);
	return 0;
}
