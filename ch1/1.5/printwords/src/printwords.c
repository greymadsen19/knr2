#include <stdio.h>

#define IN  1   /* Inside a word */
#define OUT 0   /* Outside a word */

/*
 * Characters are read
 * from a text stream and copied
 * to output. The program checks
 * if it is a new word and prints it on a newlinme
 */

int main(void) {
    int c; // character to be entered

    int state; // the state of input

    state = OUT; // set state to out

    // While the text stream is entered
    // check if it is not a word
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            putchar('\n');
        }
        else if (state == OUT) {
            state = IN;
        }
        if (state == IN) {
            putchar(c);
        }

    }

    return 0;
}
