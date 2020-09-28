#include <stddef.h>

char *mstrncpy(char *s, char *t, size_t n) {
	size_t i;
	
	for (i = 0; i < n && s[i] != '\0'; i++)
		s[i] = t[i];

	return s;
}
