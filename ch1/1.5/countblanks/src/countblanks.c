#include <stdio.h>

/* Capture input for characters
 * in the text stream. As the user
 * enters input, the program counts the
 * occurences of \n, ' ', and \t.
 * The total occurences of blanks
 * and newlines are printed to the screen
 */

int main(void) {
    int c; // the character text stream to be entered
    
    int nb, nt, nl; // counter variables

    nb = nt = nl = 0; // assign counters to 0

    // while the user enters characters
    // check if each character is a blank
    // tab or newline
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++nb;
        else if (c == '\t')
            ++nt;
        else if (c == '\n')
            ++nl;
    }

    // print the number of blanks, tabs and newlines
    printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", nb, nt, nl);

    return 0;
}
