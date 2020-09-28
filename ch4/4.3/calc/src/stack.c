#include <stdio.h>
#include <string.h>
#include <math.h>
#include "calc.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* push: push f onto the stack */
void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(int i) {
	double j;

	if (sp > 0) {
		if (i == PP)
			return val[--sp];
		else if (i == KE)
			return val[sp - 1];
		else if (i == SW) {
			j = val[sp - 1];
			val[sp - 1] = val[sp - 2];
			val[sp - 2] = j;
			return 0;
		}
		else if (i == CL) {
			sp = 0;
			return 0;
		}
		else
			return 0;

	}
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* Allow access to math functions such
 * as sin cos, exp etc.
 */
int math(char s[]) {
	double op2;

	if (!strcmp(s, "sin"))
	       	push(sin(pop(PP)));
	else if (!strcmp(s, "cos"))
	       	push(cos(pop(PP)));
	else if (!strcmp(s, "tan")) 
		push(tan(pop(PP)));
	else if (!strcmp(s, "exp")) 
		push(exp(pop(PP)));
	else if (!strcmp(s, "ln")) 
		push(log(pop(PP)));
	else if (!strcmp(s, "log")) 
		push(log10(pop(PP)));
	else if (!strcmp(s, "pow")) {
		op2 = pop(PP);
		push(pow(pop(PP), op2));
	}
	else if (!strcmp(s, "sqrt")) 
		push(sqrt(pop(PP)));
	else 
		return 0;

	return 1;
}
