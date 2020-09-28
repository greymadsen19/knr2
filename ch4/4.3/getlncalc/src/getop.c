#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define MAXLEN 1000

int my_getline(char[], int);
int line_i = 0;
char line[MAXLEN];

int getop(char s[]) {
	int c, i;
	
	if (line[line_i] =='\0') {
		if (my_getline(line, MAXLEN) == 0)
			return EOF;
		else
			line_i = 0;
	}

	while ((s[0] = c = line[line_i++]) == ' ' || c == '\t')
		;

	s[1] = '\0';
	

	i = 0;
	if (!isdigit(c) && c != '.') {
		return c;
	}

	if (isdigit(c))
		while (isdigit(s[++i] = c = line[line_i++]))
			;
	
	if (c == '.')
		while (isdigit(s[++i] = c = line[line_i++]))
			;
	s[i] = '\0';

	line_i--;

	return NUMBER;
}

int my_getline(char s[], int lim) {
	int c, i;
	
	for (i = 0; i <= lim - 1 && (c = getchar()) != EOF && c != '\n';)
		s[i++] = c;
	
	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';
	
	return i;
}
