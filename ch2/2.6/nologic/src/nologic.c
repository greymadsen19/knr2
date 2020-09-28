#include <stdio.h>

#define MAXLEN 1000

int my_getline(char str[], int len);

/* Read input for a given
 * line in a character string
 * using my implementation
 * of getline().
 * getline() is altered to not
 * use && or ||
 */
int main(void) {
    int len; // length of a line

    char line[MAXLEN]; // Current line

    while ((len = my_getline(line, MAXLEN)) > 0)
        printf("%s", line);

    return 0; 
}

/* getline() altered
 * to not use && or ||
 */
int my_getline(char s[], int max) {
    int c, i; // Character and subscript

    i = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            break;
        if (i >= max - 1)
            break;

        s[i] = c;
        ++i;
    } 

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}
