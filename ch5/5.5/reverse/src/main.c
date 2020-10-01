#include <stdio.h>

#define MAXLEN 1000

void reverse(char *);

int main(void) {
	char s[MAXLEN] = "Hello";

	printf("%s\n", s);
	reverse(s);

	printf("%s\n", s);

	return 0;
}
