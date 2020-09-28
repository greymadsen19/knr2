#include <stdio.h>

#define MAXLEN 1000
#define TABSTOP 4 

int my_getline(char str[], int len);
void entab(char to[], char from[], int tab);

/* Read input for a character
 * string in a line of input.
 * check if a character is
 * a space and if it matches
 * the length of a tabstop.
 * if so replace the spaces
 * a a tab
 */
int main(void) {
    int len; // Length of a line

    char line[MAXLEN]; // Current line
    char entabbed[MAXLEN]; // Entabbed line
    // Read input for the character string
    // and turn spaces into tabs if 
    // the tabstop length is met
    while ((len = my_getline(line, MAXLEN)) > 0) {
        entab(entabbed, line, TABSTOP);
        printf("%s", entabbed);
    }
    return 0;
} 

/* Read each individual character
 * in input and store them into
 * a character string.
 */
int my_getline(char s[], int max) {
    int c, i; // character and subscript

    // Read input for a series of characters
    // and store them into the array
    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    // If the user enteres a newline store
    // the newline in the character string as well
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    // Terminate the character string
    s[i] = '\0';

    return i;
}

/* Copy the characters of
 * the original character string
 * before doing this, determine if
 * there are spaces and if the number of
 * spaces meet the length of a tabstop
 */
void entab(char to[], char from[], int tab) {
    int i, n, ns; // The counter variables
    i = n = ns = 0; // Initialize counters

    // Since the string should only be
    // copied after the characters are
    // entabbed, read the characters
    // into a single character variable
    while ((to[i] = from[i]) != '\0') {
        if (from[i] == ' ') {
            ++ns;
            if (ns == tab)
                to[n++] = '\t';
            else
                to[n++] = from[i];
        }
        else {
            to[n++] = from[i];
            ns = 0;
        }

        ++i;
    }   
         
    to[i] = '\0';
}
