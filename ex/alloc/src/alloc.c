#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n){

	// ADDRESS + ALLOCSIZE - allocp
	// ex: 1918967432 + 10000 - 862 = 1.9e9
	// n = 1098 862 + 1098 = 1960 allocate 1960 characters (bytes)
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	} else
		return 0;
} 

void afree(char *p){
	// 191867432 + 10000 = 1.9e9
	// 201235468 true in this example
	// if address of *p is >= the address of the allocbuf array
	// and *p's address is less than the sum of allocbuf and ALLOCSIZE then
	// free the memory by setting allocp to p
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
