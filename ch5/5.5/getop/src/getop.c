#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char *s) {
	int c;

	while ((s[0] = c = getchar()) == ' ' || c == '\t');

	s[1] = '\0';

	if (!isdigit(c) && c != '.') return c;

	if (isdigit(c))	while (isdigit(*++s = c = getchar()));

	if (c == '.') while (isdigit(*++s = c = getchar()));

	*s = '\0';
	
	if (c != EOF) ungetch(c);

	return NUMBER;
}
