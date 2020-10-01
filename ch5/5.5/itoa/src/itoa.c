#include <stddef.h>
#include <string.h>

void reverse(char *s) {
	char c, *t, *u;
	
	u = s + strlen(s) - 1;

	for (t = s; t < u; ++t, --u) {
		c = *t;
		*t = *u;
		*u = c;
	}
}

void itoa(size_t n, char *s) {
	char *t = s;

	do {
		*s++ = n % 10 + '0';
	} while ((n /= 10) > 0);

	*s = '\0';

	reverse(t);
}
