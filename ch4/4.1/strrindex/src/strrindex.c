#include <string.h>

/* Search for the rightmost
 * occurence of t in s
 * if t is found in return
 * the position otherwise
 * return -1
 */
int strrindex(char s[], const char t[]) {
	int i, j, k;

	for (i = strlen(s) - strlen(t); i >= 0; i--) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;

		if (k > 0 && t[k] == '\0')
			return i;
	}

	return -1;
}
