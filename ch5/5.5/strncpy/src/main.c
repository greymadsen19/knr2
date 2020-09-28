#include <stdio.h>

#define MAXLEN 1000

char *mstrncpy(char *, char *, size_t);

int main(void) {
	char s[MAXLEN] = "Hello";
	char t[MAXLEN] = "World";

	printf("Before Copying: %s\n", s);

	mstrncpy(s, t, 4);

	printf("After Copying: %s\n", s);
	
	return 0;
}
