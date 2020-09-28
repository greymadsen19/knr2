#include <stdio.h>

#define BUFSIZE 100

static char buf[100];
static int bufp = 0;

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= 100)
		printf("ungetch: too many characters!\n");
	else if (c != EOF)
		buf[bufp++] = c;
}
