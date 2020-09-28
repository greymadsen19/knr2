#include <stdio.h>
#include "ungets.h"

int main(void) {
	const char text[] = "Hello, World!\n";
	int c;

	ungets(text);
	
	while ((c = getch()) != EOF)
		putchar(c);
	

	return 0;
}
