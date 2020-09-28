#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[]) {
	int i, c;

	static char buf = EOF;
	
	if (buf != EOF && buf != ' ' && buf != '\t'
		&& !isdigit(buf) && buf != '.') {
		c = buf;
		buf = EOF;	
		return c;
	}
	
	if (buf == EOF || buf == ' ' || buf == '\t') {
		while ((s[0] = c = getch()) == ' ' || c == '\t')
			;
	}
	else
		c = buf;
	s[1] = '\0';

	if (!isdigit(c) && c != '.')
		return c;
	
	i = 0;
	
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	
	s[i] = '\0';
	
	buf = c;
	
	return NUMBER;
}
