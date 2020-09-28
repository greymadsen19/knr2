#include <stdio.h>

/* Read input from a text stream
 * and copy its input to output.
 * if the character is a tab,
 * backspace, or back slash
 * print the corresponsing escape
 * sequence
 */

int main(void) {
    int c; // Store the character in the text stream

    // While the character are entered
    // check if tab, backslash or backspace
    // and print the corresponding escape
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\b') {
            putchar('\\');
            putchar('b');
        }
        else if( c == '\\') {
            putchar('\\');
           // putchar('\\');
        }

        putchar(c);
    }

    return 0;
}
