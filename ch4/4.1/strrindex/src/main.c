#include <stdio.h>
#include "main.h"

/* Search for the rightmost
 * occurence of s2 in s1
 * and display a message indicating
 * if it is found or not.
 */
int main(void) {
	char line[MAXLINE];
	const char pattern[] = "ould";

	while (my_getline(line, MAXLINE) > 0) {
		if (strrindex(line, pattern) >= 0)
			printf("Pattern found!\n");
		else
			printf("Pattern not found!\n");
	}

	return 0;
}
