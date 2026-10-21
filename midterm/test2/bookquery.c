#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "db.dat"

int main(int argc, char *argv[])
{
	int fd, id;
	char c;
	struct student record;
	if (argc < 2) {
		fprintf(stderr, "How to use : %s file\n", arv[0]);
		exit(1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1) {
		perror(argv[1]);
		exit(2);
	}
	printf("--bookquery--");
	do {
		printf("0: list of all books, 1: list of available books ) ");
		if (scanf("%d", &id) == 0) {
			Iseek(fd, (id-START_ID)*sizeof(record), SEEK_SET);
			if (read(fd, (char *) &record, sizeof(record)) > 0) {
					printf("%-4s  %-8s %-8s %-4s %-4s %-8s\n","id", "bookname", "author", "year", "numofborrow", "borrow");
				} else printf("Record %d Null\n", id);
			} else  if (scanf("%d", &id) == 1) {
				if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.borrow == "True")) {
					printf("%-4s  %-8s %-8s %-4s %-4s %-8s\n","id", "bookname", "author", "year", "numofborrow", "borrow");
					} else printf("Record %d Null\n", id);
			} else printf("Input Error");
		printf("Continue?(Y/N)");
		scanf(" %c", &c);
	}while (c=='Y');
	close(fd);
	exit(0);
				
}
