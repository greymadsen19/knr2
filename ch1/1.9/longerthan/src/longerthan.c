#include <stdio.h>

#define MAXLEN 1000 // Max length of a line
#define MINLEN 80 // Min length of a line

int my_getline(char str[], int max);

/* Read input
 * for characters in a text
 * stream which are stored in
 * an array. Determine if the line
 * is longer than 80 characters
 * if so then the line is displayed
 * else the line is skipped and
 * the next line is analyzed
 */
int main(void) {
    int len; // Length of a line
    char line[MAXLEN]; // The line being stored

    while ((len = my_getline(line, MAXLEN)) > 0)
        if (len > MINLEN)
            printf("%s", line);

    return 0;
}

/* Read input for each character
 * in the text stream of a line
 * if the character is not a newline
 * and the EOF isn't reached and
 * the max length isn't reached
 * then continue reading input for characters
 * if the character is a newline store a newline at
 * the end of the line. When input is done
 * store the null termination key at the end of
 * the character array
 */
int my_getline(char s[], int max) {
    int c, i; // Character and the counter being worked with

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c; // Store the character into the array

    // Store the newline into the array
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0'; // Store a 0 at the end of the string

    return i;
}
