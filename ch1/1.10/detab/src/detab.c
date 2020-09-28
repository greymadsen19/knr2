#include <stdio.h>

#define MAXLEN 	1000
#define TABSTOP	4

int my_getline(char str[], int max);
void detab(char to[], char from[]);

/* Read input for a string of
 * characters for an individual line.
 * determine if a character is a tab
 * and parse it into the the length
 * of a tabstop where the tabstop
 * is n number of columns
 */
int main(void) {
    int len; // Length of a line
    
    char line[MAXLEN]; // Current line
    char detabbed[MAXLEN]; // Detabbed line
    
    // Read line of input
    // and print a detabbed version of the line
    while ((len = my_getline(line, MAXLEN)) > 0) {
        detab(detabbed, line);
        printf("%s", detabbed);
    }

    return 0;
}

/* Read each character in a
 * line until a new line character
 * is entered
 */
int my_getline(char s[], int max) {
    int c, i; // Character and subscript
    
    // Read each character and store them into an array
    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    
    s[i] = '\0';

    return i;
}

/* Loop through the subscripts
 * of a character string checking
 * if it is a tab. If it is replace
 * the tab with spaces at n column.
 * else move to the next character doing
 * nothing
 */
void detab(char to[], char from[]) {
    int i, j, n, nt;

    // Initialize I and J counters to 0
    // and start n at the 0th column (using 0 based subscripts)
    // of the tabstop
    nt = i = j = n = 0;

    // Store the original character string
    // into the new one
    while ((to[j] = from[i]) != '\0') {
        // If there is a tabstop
        // loop at n storing a space
        if (to[j] == '\t') {
            ++nt;
            for (; n < TABSTOP * nt; ++j, ++n)
                to[j] = ' ';    
        }
        else {
            ++j;
            //nt = 0;
        }

        ++i;
    }
}
