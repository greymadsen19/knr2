#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calc.h"

#define MAXOP 100

/* Extended PostFix calculator 
 * thatt accepts the four basic
 * arithmetic operands as well as
 * an additional operand for handling modulus.
 * It also will allow for math commands such as
 * sin or exp 
 */
int main(void) {
	int type, var, i;
	double op2;
	char str[MAXOP];

	enum State CMD; // Track the ccustom stack commands

	double vars[26]; // Store 26 variables 
	
	// Display a prompt to the user
	prompt();

	// Initialize the variables to 0
	for (i = 0; i < 26; i++)
		vars[i] = 0.0;
	while ((type = getop(str)) != EOF) {
		CMD = PP;
		switch (type) {
			case NUMBER:
				push(atof(str));
				break;
			case NAME:
				math(str);
				break;
			case '+':
				push(pop(CMD) + pop(CMD));
				break;
			case '*':
				push(pop(CMD) * pop(CMD));
				break;
			case '-':
				op2 = pop(CMD);
				push(pop(CMD) - op2);
				break;
			case '/':
				op2 = pop(CMD);
				if (op2 != 0.0)
					push(pop(CMD) / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop(CMD);
				if (op2 != 0.0)
					push((int)pop(CMD) % (int)op2);
				else
					printf("error: zero divisor\n");
				break;
			case '=':
				if (var >= 'A' && var <= 'Z') {
					pop(PP);
					push(vars[var - 'A'] = pop(PP));
				}
				else
					printf("error: no variable stored.\n");

				break;
			case '^':
				CMD = KE; // Keep the number on the stack
				printf("%.8g\n", pop(CMD));
				break;
			case '~':
				CMD = KE;
				push(pop(CMD));
				break;
			case '|':
				CMD = SW;
				pop(CMD);
				break;
			case '!':
				CMD = CL;
				pop(CMD);
				printf("Stack Cleared.\n");
				break;
			case '?':
				printf("^: print top of stack ~: copy last value |: swap two previous values !: clear stack\n");
				printf("        sin: sine(x) cos: cosine(x) tag: tangent(x) exp: exponent(x)\n");
				printf("         ln: log(x) log: log10(x) pow: pow(x, y) sqrt: sqrt(x)\n\n");
				push('?');
				break;
			case '\n':
				//printf("%.8g\n", pop(CMD));
				op2 = (pop(CMD));
				op2 != '?' ? printf("%.8g\n", op2) : 0;
				break;
			default:
				if (type >= 'A' && type <= 'Z')
					push(vars[type - 'A']);
				else
					printf("error: unknown command %s\n", str);
				break;
		}

		var = type; // Set the variable the value in input
	}

	return 0;
}
