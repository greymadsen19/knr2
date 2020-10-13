#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

static int sp = 0;
static double val[MAXVAL];
static double *pval = &val[0];

void push(double f) {
	if (sp++ <= MAXVAL) *pval++ = f;
	else printf("error: stack full, can't push %f\n", f);
}

double pop(void) {
	if (sp-- > 0) return *--pval;
	else printf("error: stack empty\n");

	return 0.0;
}

