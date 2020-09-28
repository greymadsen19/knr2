#include <stdio.h>

#define MAXLEN 1000

void itoa(unsigned int n, char s[], int w);

/* Create an alternate version
 * of itoa with three arguments
 * where the third argument
 * specifies the field-width
 * of a string. If the string
 * is less than the field-width
 * than spaces are padded to the
 * left of the string.
 */
int main(void) {
    unsigned int num;
    int width;
    char str[MAXLEN];

    // Set the number and field width
    num = 163;
    width  = 8;

    itoa(num, str, width);

    printf("%s\n", str);
    
    return 0;
}

/* itoa - convert n to characters
 * in a string if the integer
 * is small than the given field-width
 * than pad spaces to the left of the number
 */
void itoa(unsigned int num, char str[], int width) {
    int i, j; // Counters
    int tmp;
    
    i = 0;
    j = 0;
    tmp = num;
    
    do {
	j++;
    } while ((tmp /= 10) != 0);
    // Pad spaces two the left
    while (j++ < width)
	str[i++] = ' ';
    
    do {
       	str[i++]  = num % 10 + '0'; // Store digit
    } while ((num /= 10) > 0);

    str[i] = '\0';
}

