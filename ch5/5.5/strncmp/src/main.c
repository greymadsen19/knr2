#include <stdio.h>

#define MAXLEN 1000

int mstrncmp(char *, char *, size_t);

int main(void) {
	char s[MAXLEN] = "Hello, World! How are you";
	char t[MAXLEN] = "Hello";

	int i;
	i = mstrncmp(s, t, 5);

	printf("%d", i);

	return 0;
}
