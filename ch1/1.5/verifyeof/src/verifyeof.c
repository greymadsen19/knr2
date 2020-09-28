#include <stdio.h>

/* The program accepts individual
 * character input from the text stream
 * that the use entered with the keyboard.
 * While the input has not reached the end (EOF)
 * continue accepting input until EOF is reached
 * then print the value of c = getchar() != EOF
 */

int main(void) {
    int c; // The character to be entered

    // While the user enters into the text stream
    // print the value of EOF
    while (c = getchar() != EOF)
        printf("%d\n", c);

    /* getchar() != EOF
     * should never be 0
     * because that would indicate
     * that input has been terminated
     * therefore it would be 0 after EOF
     * has been reached which is never occurs
     * when this is running
     */

    return 0;
}
