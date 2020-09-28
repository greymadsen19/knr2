#include <stdio.h>

int lower(int c);

/* Read input for characters
 * and print them in lower
 * case form
 * using a custom version
 * of lower
 */
int main(void) {
    int c; // Character

    // Read character
    printf("Enter a character: ");
    c = getchar();

    printf("In lower case: %c\n", lower(c));

    return 0;
}

/* Convert the character
 * to lower case
 */
int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c += 'a' - 'A'  : c;
}
