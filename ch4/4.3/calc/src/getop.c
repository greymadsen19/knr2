#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "calc.h"

/* getop: get the next operator or numeric operand */
int getop(char str[]) {
	int i, c;

	while ((str[0] = c = getch()) == ' ' || c == '\t')
		;

	str[1] = '\0';


	i = 0;

	if (str[0] == '-'|| str[0] == '+') {
		str[++i] = c = getch();
		if (!isdigit(c) && c != '.') {
			ungetch(c);
			return str[0];
		}
	}

	if (islower(c)) {
		while (isalpha(str[++i] = c = getch()))
			;
		str[i] = '\0';
			if (c != EOF)
				ungetch(c);
		return  (strlen(str)) == 1 ? c : NAME;
	}

	if (!isdigit(c) && c != '.')
		return c;

	if (isdigit(c))
		while(isdigit(str[++i] = c = getch()))
			;
	if (c == '.')
		while(isdigit(str[++i] = c = getch()))
			;
	str[i] = '\0';
	if (c != EOF)
		ungetch(c);

	return NUMBER;
}
