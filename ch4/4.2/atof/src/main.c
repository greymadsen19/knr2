#include <stdio.h>
#include "main.h"

/* This is a rudimentary calculator
 * that takes in basic addition and
 * subtraction of fractional numbers including
 * numbers written in exponatial notation.
 * If the number is in exponential form
 * then in addition to transfering the decimal place of
 * the significand when converting the string to decimal
 * it will also accoringly transfer the decimal of the mantissa
 * accordingly
 */
int main(void) {
	double sum;
	char line[MAXLINE];

	sum = 0;
	while (my_getline(line, MAXLINE) > 0 ) {
		printf("%g\n", sum += atof(line));
	}

	return 0;
}
