#include <stdio.h>

#define MAXLEN 1000


size_t mgetline(char *, size_t);

int main(void){
	char s[MAXLEN];

	while ((mgetline(s, MAXLEN)) > 0) {
		printf("%s\n", s);
	}

	return 0;
}
