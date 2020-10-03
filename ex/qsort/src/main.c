#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void my_qsort(int [], int, int);

int main(void) {
	int c, i;
	int len;
	
	srand(time(NULL));
	
	printf("Enter the length of an array to be sorted.\n");
	c = getchar();
	len = c - '0';
	int v[len];
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
