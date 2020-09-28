#include <stddef.h>

char *mstrncat(char *s, char *t, size_t n) {
	size_t i;
	
	while (*++s);

	for (i = 0; i < n && (*s++ = *t++); i++);
	
	return s;
}
