#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *alloc(int);
void afree(char*);

int main(void){
	char *a;
	char *b;

	int n;
	
	srand(time(NULL));
	n = rand() % 10000 + 1;

	a = alloc(n);

	printf("Allocated %d characters\n", n);

	n = rand() % 10000 + 1;

	b = alloc(n);
	printf("Allocated %d characters\n", n);

	afree(b);
	printf("Freed character string b\n");
	afree(a);
	printf("Freed character string a\n");
	
	
	return 0;
}
