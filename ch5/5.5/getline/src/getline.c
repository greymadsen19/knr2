#include <stdio.h>
#include <string.h>

size_t mgetline(char *s, int lim) {
	int c;
	char *sp = s;
	
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;

	if (c == '\n') 
		*s++ = c;


	*s = '\0';

	return strlen(sp);
}

