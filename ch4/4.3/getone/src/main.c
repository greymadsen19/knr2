#include <stdio.h>
#include "getch.h"

int main(void) {
	int c;
	int i = 0;
	
	while ((c = getch()) != EOF) {
		++i;
		if (i > 1)
			ungetch('!');
		else
			putchar(c);
	}
	
	return 0;
}
