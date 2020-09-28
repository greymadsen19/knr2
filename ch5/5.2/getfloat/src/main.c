#include <stdio.h>

#define SIZE 1000

int getfloat(float *);

int main(void) {
	int n, i;
	float array[SIZE];

	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		;

	printf("\n");

	for (i = 0; i < n; i++)
		printf("%f", array[i]);

	return 0;
}
