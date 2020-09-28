#include <stdio.h>

#define MAXLEN 1000

void itob(int n, char s[], int b);
void reverse(char str[]);

/* Convert an integer
 * into the character representation
 * of itself in base b and store
 * the result in a string
 */
int main(void) {
    int num; // The number to be converted
    int base; // Base to convert to
    base = 8;
    num = -12313; // Set the integer
    
    char str[MAXLEN]; // The string to store the converted integer

    itob(num, str, base);

    if (base != 2 && base != 8 && base  != 16) {
	printf("Invalid Base! You can only convert to: binary, octal an hexadecimal.\n");
	return 0;
    }

    printf("Original Number: %d\n", num);
    printf("Converted Number: %s\n", str);
    
    return 0;
}

/* Convert the integer to its character
 * representation in a different base
 * and store it in the string
 */
void itob(int num, char str[], int base) {
    int i, j; // Counter variables
    int sign;

    i = 0;

    if ((sign = num) < 0) {
	str[i++] = '-';
	num = -num;
    }
    
    /* Set the first two characters
     * based on the base that the number is converting
     * to IE base 2 begins with 0b
     */
    str[i++] = '0';
    switch (base) {
    case 2:
	str[i++] = 'b';
	break;
    case 8:
	str[i++] = '0';
	break;
    case 16:
	str[i++] = 'x';
	break;
    }

    
    // Convert to a number system in base b
    do {
	j = num % base;
	str[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
    } while ((num /= base) > 0);

    str[i] = '\0';

    reverse(str);
}

/* Reverse the string so that
 * the digits in the result
 * are in the correct order
 */
void reverse(char str[]) {
    int i, j, c; // Counters and temporary character

    // Generate the length of the string
    for (j = 0; str[j] != '\0'; j++)
	;

    --j;
    
    // Reverse the string
    for (i = 3; i < j; i++, j--) {
	c = str[i];
	str[i] = str[j];
	str[j] = c;
    }
}
