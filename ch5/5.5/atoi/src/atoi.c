#include <string.h>
#include "atoi.h"

int matoi(char *s) {
	int n;

	for (n = 0; *s >= '0' && *s <= '9';)
		n = 10 * n + (*s++ - '0');

	return n;
}

size_t mgetline(char *s, size_t lim) {
	int c;
	char *sp = s;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;

	if (c == '\n')
		*s++ = c;

	*s = '\0';

	return strlen(sp);
}
