#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void my_qsort(int [], int, int);

int main(void) {
	int i;
	const int len = 9;
	int v[len];	

	srand(time(NULL));
	
	for (i = 0; i < len;) {
		v[i++] = (rand() % 9) + 1;
	}
	
	my_qsort(v, 0, len - 1);
	
	if (len > 0) {
		printf("sorted array: ");
		for (i = 0; i < len; i++)
			printf("%d ", v[i]);
	
		putchar('\n');
	}
		

	return 0;
}
