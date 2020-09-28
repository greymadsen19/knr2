#include <stdio.h>

/* The program accepts input
 * for the text stream.
 * The input is copied to output
 * where if a blank is entered,
 * only one blank is printed
 */

int main(void) {
    int c; // For character input

    /*
     * Copy the input to output
     * and print only one space if
     * a space is entered
     */
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            putchar(c);

            // if there are blanks precedung the first
            // skip them
            while ((c = getchar()) == ' ' && c != EOF)
                ;
        }

        putchar(c);
    }

    return 0;
}
