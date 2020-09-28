#include <stdio.h>

/* getline function from K&R C book */
int my_getline(char str[], int max) {
	int c, i;

	for (i = 0; i <= max - 1 && (c = getchar()) != EOF && c != '\n';)
		str[i++] = c;

	if (c == '\n')
		str[i++] = c;

	str[i] = '\0';

	return i;
}
