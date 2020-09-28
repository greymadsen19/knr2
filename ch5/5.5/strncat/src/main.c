#include <stdio.h>

#define MAXLEN 1000

char *mstrncat(char *, char *, size_t);

int main(void) {
	char s[MAXLEN] = "Hello";
	char t[MAXLEN] = "World";

	printf("%s\n", s);

	mstrncat(s, t, 3);

	printf("%s\n", s);

	return 0;
}
