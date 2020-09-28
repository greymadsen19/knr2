#include <stdio.h>

#define SIZE 1000

int getint(int *);

int main(void) {
	int n, array[SIZE], i;
	
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
	
	printf("\n");

	for (i = 0; i < n; i++)
		printf("%d", array[i]);
	return 0;
}
