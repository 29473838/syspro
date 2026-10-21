#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "db.dat"

int main(int argc, char *argv[])
{
	int fd, id;
	char c, name;
	struct student record;
	if (argc < 2) {
		fprintf(stderr, "How to use : %s file\n", arv[0]);
		exit(1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1) {
		perror(argv[1]);
		exit(2);
	}
	do {
		printf("input name of book");
		if (scanf("%s", &name) == (char *strcmp(const char *name, char *record.name, size_name n)) 
			Iseek(fd, (name - START_ID)*sizeof(record), SEEK_SET);
			if (read(fd, (char *) &record, sizeof(record)) > 0) {
					printf("%-4s  %-8s %-8s %-4s %-4s %-8s\n","id", "bookname", "author", "year", "numofborrow", "borrow");
				} else printf("Record %d Null\n", id);
			} else printf("not found book name : ", &name);
		printf("Continue?(Y/N)");
		scanf(" %c", &c);
	}while (c=='Y');
	close(fd);
	exit(0);
				
}
