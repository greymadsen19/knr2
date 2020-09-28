#include <stddef.h>

int mstrncmp(char *s, char *t, size_t n) {
	while (n-- && *s == *t && *s != '\0') {
		++s;
		++t;
	}

	if (*s > *t)
		return -1;
	else if (*s < *t)
		return 1;

	return 0;
}
