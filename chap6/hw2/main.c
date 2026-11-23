#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>

int opt_i, opt_p, opt_Q;

char type(mode_t m)
{
	if (S_ISREG(m)) return '-';
	if (S_ISDIR(m)) return 'd';
	if (S_ISCHR(m)) return 'c';
	if (S_ISBLK(m)) return 'b';
	if (S_ISLNK(m)) return 'l';
	if (S_ISFIFO(m)) return 'p';
	return 's';
}

char *perm(mode_t m)
{
	static char p[10];
	int i;
	strcpy(p, "---------");
	for (i = 0; i < 9; i++)
		if (m & (0400 >> i))
			p[i] = "rwx"[i % 3];
	return p;
}

void printStat(char *file, struct stat *st)
{
	if (opt_i) printf("%lu ", (unsigned long)st->st_ino);
	printf("%5ld ", (long)st->st_blocks);
	printf("%c%s ", type(st->st_mode), perm(st->st_mode));
	printf("%3ld ", (long)st->st_nlink);
	printf("%s %s ", getpwuid(st->st_uid)->pw_name, getgrgid(st->st_gid)->gr_name);
	printf("%9ld ", (long)st->st_size);
	printf("%.12s ", ctime(&st->st_mtime) + 4);
	if (opt_Q) printf("\"%s\"", file);
	else printf("%s", file);
	if (opt_p && S_ISDIR(st->st_mode)) putchar('/');
	putchar('\n');
}

int main(int argc, char **argv)
{
	DIR *dp;
	char *dir = ".", *s;
	struct stat st;
	struct dirent *d;
	char path[BUFSIZ + 1];
	int i;

	for (i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			for (s = argv[i] + 1; *s; s++) {
				if (*s == 'i') opt_i = 1;
				else if (*s == 'p') opt_p = 1;
				else if (*s == 'Q') opt_Q = 1;
			}
		} else dir = argv[i];
	}

	if ((dp = opendir(dir)) == NULL) {
		perror(dir);
		exit(1);
	}
	while ((d = readdir(dp)) != NULL) {
		sprintf(path, "%s/%s", dir, d->d_name);
		if (lstat(path, &st) < 0)
			perror(path);
		else
			printStat(d->d_name, &st);
	}
	closedir(dp);
	exit(0);
}

