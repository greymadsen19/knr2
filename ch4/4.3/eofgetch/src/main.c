#include <stdio.h>
#include "getch.h"

int main(void) {
	int c;

	ungetch(EOF);
	
	while ((c = getch()) != EOF)
		putchar(c);

	return 0;
}
