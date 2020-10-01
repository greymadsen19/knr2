#include <string.h>

void reverse(char *s) {
	char c, *sp, *t;

	t = s + strlen(s) - 1;

	for (sp = s; sp < t; ++sp, --t) {
		c = *sp;
		*sp = *t;
		*t = c;
	}
}
