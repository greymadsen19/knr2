#include "atoi.h"

#define MAXLEN 1000

int main(void) {
	char s[MAXLEN];
	size_t lim = MAXLEN;

	printf("Enter a number: ");
	mgetline(s, lim);

	printf("String: %s", s);
	
	printf("Converted: %d\n", matoi(s));

	return 0;

}
