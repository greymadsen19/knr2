#include <stdio.h>
#include <string.h>

void reverse(char [], int, int);

int main(void) {
	char s[] = "hello world!";	

	printf("%s\n", s);

	reverse(s, 0, strlen(s) - 1);
	
	printf("reversed: %s\n", s);
	
	return 0;	
}
