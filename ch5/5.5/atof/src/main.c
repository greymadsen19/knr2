#include "atof.h"

#define MAXLEN 1000

int main(void) {
	char s[MAXLEN];
	size_t lim = MAXLEN;
	float _Float;

	printf("Enter a decimal number: ");
	mgetline(s, lim);

	_Float = matof(s);
	printf("Converted to float: %f", _Float);

	return 0;
}
