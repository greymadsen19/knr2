#include <stdio.h>

int strend(char *, char *);

int main(void) {
	char *s = "Hello World!";
	char *t = "ld!";

	if (strend(s, t))
		printf("String %s contains the string %s\n", s, t);
	else
		printf("String %s does not contain the string %s\n", s, t);

	return 0;
}
