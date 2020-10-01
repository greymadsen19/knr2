#include <ctype.h>
#include <string.h>
#include "atof.h"

float matof(char *s) {
	float val, power;
	int sign;

	while (isspace(*s)) ++s;

	sign = (*s == '-') ? -1 : 1;

	if (*s == '-' || *s == '+') ++s;

	for (val = 0.0f; isdigit(*s); s++)
		val = 10.0f * val + (*s - '0');
	
	if (*s == '.') ++s;

	for (power = 1.0f; isdigit(*s); s++) {
		val = 10.0f * val + (*s - '0');
		power *= 10.0f;
	}

	return sign * val / power;
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
