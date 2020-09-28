#include <stdio.h>

#define MAXLEN 1000

void my_strcat(char *, char *);

int main(void) {
	char s[MAXLEN] = "Hello ";
	char t[MAXLEN] = "World!";

	printf("Original String: %s\n", s);
	
	my_strcat(s, t);

	printf("Copied String: %s\n", s);

	return 0;
}
