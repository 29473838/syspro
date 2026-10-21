
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "db.bat"

int main(int argc, char *argv[])
{
	int fd, n,id;
	char c;
	struct student record;
	if (argc <2) {
		fprintf(stderr, "How to use : %s file\n", argv[0]);
		exit(1);
	}		
	if ((fd = open(argv[1], O_RDWR)) == -1) {
		perror(argv[1]);
		exit(2);
	}
	printf("--bookupdate--");
	do {
		printf("0 bookId: borrow book, 1 bookId: return book ) ");
		scanf("%d %d", &n, &id);
		if (n == 1) {
			lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
			if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0)) {
				 if (record.borrow == False) {
				 	printf("You've got bellow book..");
					record.nomofborrow = record.nomofborrow +1;
					record.borrow = False;
					lseek(fd, (long) -sizeof(record, SEEK_CUR);
					write(fd, (char *) &record, sizeof(record));

					printf("%-4s  %-8s %-8s %-4s %-4s %-8s\n","id", "bookname", "author", "year", "numofborrow", "borrow");
				 } else {
				 	printf("You cannot borrow below book since it has been booked.");
		if (n == 1) {
 			lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
 			if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0)) {
 				if (record.borrow == True) {
 					printf("You've returned bellow book..");
					record.borrow = True;
					lseek(fd, (long) -sizeof(record, SEEK_CUR);
					write(fd, (char *) &record, sizeof(record));
					printf("%-4s  %-8s %-8s %-4s %-4s %-8s\n","id", "bookname", "author", "year", "numofborrow", "borrow");
				} else {
 					printf("You cannot returned book.");
					printf("%-4s  %-8s %-8s %-4s %-4s %-8s\n","id", "bookname", "author", "year", "numofborrow", "borrow");
				 }
			}
		} else printf("Insert Error\n");
		printf("Continue?(Y/N)\n");
		scanf(" %c", &c);
	} while (c == 'Y');
	close(fd);
	exit(0);
}


