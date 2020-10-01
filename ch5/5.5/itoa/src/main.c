#include <stdio.h>

void itoa(size_t, char *);

int main(void) {
	char s[1000];

	itoa(132, s);

	printf("%s\n", s);

	return 0;
}
