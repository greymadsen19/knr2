#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ssort(int [], int);

int main(void) {
	int v[10];
	int n;
	int i;

	for (n = 0; n < 10; n++)
		;

	srand(time(NULL));

	for (i = 0; i < n; i++)
		v[i] = rand() % 9 + 1;

	printf("Array: [");
	
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);

	printf("]\n");

	ssort(v, n);

	printf("Sorted: [");
	
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);

	printf("]\n");

	return 0;
}
