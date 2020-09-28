#include <stdio.h>

#define MAXLEN 1000

int my_getline(char s[], int max);
void reverse(char to[], char from[]);

/* Accept input for
 * a series of characters into
 * a character array.
 * Reverse the character
 * string and display
 * it in reverse form
 */
int main(void) {
    int len; // Length of line
    char line[MAXLEN]; // Current line
    char reversed[MAXLEN]; // Reversed line
    
    while ((len = my_getline(line, MAXLEN)) > 0)
        reverse(reversed, line);

    // Print the reversed line
    printf("%s\n", reversed);

    return 0;
}

/* Accept input for characters
 * from a text stream and assign
 * them to an array. At the end of
 * the string append 0 to
 * the string
 */
int my_getline(char s[], int max) {
    int c, i; // Character and the counter

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

/* Reverse an array of characters */
void reverse(char to[], char from[]) {
    int i, j, len; // The counters and length

    // Get the length of the string
    for (len = 0; from[len] != '\0' && from[len] != '\n'; ++len)
        ;

    for (i = 0, j = len; i <= len; ++i, --j) {
        to[j] = from[i];
    }

    to[i] = '\0';
}
