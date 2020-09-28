#include <stdio.h>

int buf = EOF;

int getch(void) {
	return (buf != EOF) ? (buf = EOF) : (buf = getchar());
}

void ungetch(int c) {
	if (buf != EOF)
		printf("ungetch: error too many characters!\n");
	else
		buf = c;
}
