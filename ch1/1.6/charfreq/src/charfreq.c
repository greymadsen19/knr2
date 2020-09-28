#include <stdio.h>

#define CHARS 128

/* Accept input for characters
 * until user prommpts EOF
 * on the keyboard. As they
 * enter characters that exist
 * on the keyboard values in the
 * subscripts of an array
 * are incremented each time a character is entered
 */

int main(void) {
    int c, ascii[CHARS]; // The character entered and the array to store character frequencies

    // Initialize array
    for (int i = 0; i < 128; ++i) {
        ascii[i] = 0;
    }

    // Accept input
    while ((c = getchar()) != EOF) {
        ++ascii[c];
    }

    // Print a histogram veritically
    for (int i = 0; i < CHARS; ++i) {
        putchar(i);

        for (int j = 0; j < ascii[i]; ++j) {
            putchar('*');
        }

        putchar('\n');
    }

    return 0;
}
