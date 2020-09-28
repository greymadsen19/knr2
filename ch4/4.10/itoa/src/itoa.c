#include <stdlib.h>

int itoa (int n, char s[]) {
	int i;

	if (n < 0)
		n = -n;
	else if (n / 10 != 0)
		i = itoa(n / 10, s);

	s[i++] = abs(n % 10) + '0';
	
	s[i] = '\0';

	return i;
}
