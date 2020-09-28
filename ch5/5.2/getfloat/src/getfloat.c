#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int getfloat(float *pn) {
	int c, sign;
	float divisor;

	while (isspace(c = getchar()))
		;

	while (!isdigit(c) && c != EOF && c != '-' && c != '+')
		ungetch(c);

	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-')
		c = getch();

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');

	if (c == '.')
		c = getchar();

	for (divisor = 1.0f; isdigit(c); c = getchar()) {
		*pn = 10.0f * *pn + (c - '0') ;
		divisor *= 10.0f;
	}

	*pn *= sign / divisor;

	if (c != EOF)
		ungetch(c);

	return c;	
}
