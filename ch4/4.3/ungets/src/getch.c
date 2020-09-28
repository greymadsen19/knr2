#include <stdio.h>
#include <string.h>
#include "ungets.h"

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

// get a potential pushed back character
int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

// push a character back on input
void ungetch(int c) {
	if (bufp == BUFSIZE)
		printf("ungetch: too many arguments!\n");
	else
		buf[bufp++] = c;
}

// push back a string onto input
void ungets(const char str[]) {
	int len = strlen(str);
	
	while (len > 0)
		ungetch(str[--len]);	
}
