#include <stdio.h>


int mstrindex(char *, char *);

int main(void) {
	char *s = "Hello World!";
	char *t = "lo Wor";

	printf("Index of t in s %d\n", mstrindex(s, t));

	return 0;
}

