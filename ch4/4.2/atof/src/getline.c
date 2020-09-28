#include <stdio.h>

/* K$R C getline function */
int my_getline(char s[], int max) {
	int c, i;

	for (i = 0; i <= max - 1 && (c = getchar()) != EOF && c != '\n';)
		s[i++] = c;

	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;	
}
