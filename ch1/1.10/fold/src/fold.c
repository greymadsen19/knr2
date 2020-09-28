#include <stdio.h>

#define MAXLEN 1000
#define FOLDLIM 40

int my_getline(char str[], int len);
int skipblanks(char str[], int i);
void fold(char to[], char from[], int lim);

/* Read input for a character string
 * and print a copy of the string
 * Check if a line is greater than the
 * line limit and fold the line to the
 * next line. Also if there are blanks
 * before the column chosen they will
 * be ignored
 */
int main (void) {
    int len; // Length of a line

    char line[MAXLEN]; // Current line
    char folded[MAXLEN]; // Folded line

    // Read the characters of a line
    while((len = my_getline(line, MAXLEN)) > 0) {
        if (len > FOLDLIM) {
            fold(folded, line, FOLDLIM);
            printf("%s", folded);
        }
        else {
            printf("%s", line);
        }
    }

    return 0;
}

/* Read in each individual
 * character and store them
 * in a character string
 */
int my_getline(char s[], int max) {
    int c, i; // Character and subscript

    // Read in the characters into the string
    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    // Store the newline into the string
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

/* Copy a character string
 * into another. Check if a character
 * is a space of a tab. Also track the
 * number of characters so that the number of characters can be compared with
 * the limit. If the number of characters
 * exceed the limit store a newline if the
 * last character was a blank then move the index
 * to where the blanks is and skip any blanks that are before the newline
 */
void fold(char to[], char from[], int lim) {
    int i, nc; // Counters
    int blanks; // Track the blanks

    // Copy the old string into the new
    // Checking for the number of characters
    // if number of characters and there are
    // blanks skip the blanks at the end    // of a line and store a newline into
    // the copy
    while ((to[i] = from[i]) != '\0') {
        // Counter the number of characters
        ++nc;
        
        // Track the latest blank
        if (from[i] == ' ' || from[i] == '\t')
            blanks = i; 

        // Fold the line if the limit has been exceeded
        // Handle blanks by ignoring preceding blanks
        if (nc >= lim && blanks != 0) {
            to[blanks] = '\n';
            i = blanks;

            i = skipblanks(from, i);

            // Reset counters
            nc = blanks = 0;
        }

        ++i;
    }

    to[i] = '\0';
}

// Skip blanks that exist before the newline
int skipblanks(char str[], int i) {
    while (str[i] == ' ' || str[i] == '\t')
        ++i;

    return --i;
}
