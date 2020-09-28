#include <stdio.h>

#define MAXLEN 1000

void itoa(int, char []);


int main(void) {
	int n;
	char s[MAXLEN];	
	
	n = 128;
	
	itoa(n, s);

	printf("itoa: %s\n", s);
	
	return 0;
}
