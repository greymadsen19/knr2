#include <stdio.h>

#define MAXWD   10 // Max number of words

/* Input characters
 * from the keyboard and determine
 * if the character is whitespace.
 * If it is track the number of words
 * and reset the length
 * after doing this
 * print a vertical histogram starting at
 * the longest length.
 */

int main(void) {
    int c; // The character to be entered

    // Store the lengths of the words, and the counters
    int lengths[MAXWD], nc, nw;

    // Initialize the array
    for (int i = 0; i < 10; ++i) {
        lengths[i] = 0;
    }

    // Initialize counter 
    nc = nw = 0;

    // Read character input
    while ((c = getchar()) != EOF) {
        ++nc;
        // Set the state to out if c is a blank
        if (c == ' ' || c == '\n' || c == '\t') {

            // Set the lengths excluding the space
            lengths[nw] = nc - 1;

            // Count words
            ++nw;

            // Reset num characters
            nc = 0;
        }
    }

    // Print the histogram
    for (int i = MAXWD; i >= 1; --i) {
        
        for (int j = 0; j <= nw; ++j) {
            if (i <= lengths[j]) 
                putchar('*');
            else
                putchar(' ');
        }

        printf("\n");
    }

    return 0;
}
