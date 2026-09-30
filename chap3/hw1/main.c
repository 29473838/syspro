#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE];
char longest[MAXLINE];
char str[5][MAXLINE];

main() {
	int len;
	int max;
	int i;
	int j;
	char temp[MAXLINE];

	max = 0;

	i = 0;
	while (i < 5) {
		gets(line);
		copy(line, str[i]);
		i++;
	}

	i = 0;
	while (i < 5) {
		max = 0;
		j = 0;

		while (j < 5) {
			len = strlen(str[j]);

			if (len > max) {
				max = len;
				copy(str[j], longest);
			}

			j++;
		}

		j = 0;
		while (j < 5) {
			if (strlen(str[j]) == max) {
				copy(str[j], temp);
				copy(str[j], longest);
				copy(temp, str[j]);
				str[j][0] = '\0';
				break;
			}
			j++;
		}

		printf("%s \n", longest);
		i++;
	}

	return 0;
}
