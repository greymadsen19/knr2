#include <stdio.h>

#define swap(t, x, y) \
	t z; \
	z = x; \
	x = y; \
	y = z; 

int main(void) {
	int x, y;
	x = 2;
	y = 4;
	printf("%d %d\n", x, y);
	
	swap(int, x, y);
	printf("%d %d\n", x, y);
	return 0;
}
