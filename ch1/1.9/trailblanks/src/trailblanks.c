#include <stdio.h>

#define MAXLEN 1000

int my_getline(char s[], int max);
void remtrail(char s[], int max);

/* Read input for characters
 * into an array of characters.
 * Check if the line is
 * only a newline (first subscript
 * contains '\n'). Loop from the
 * end of the array to check if there
 * are blanks or tabs
 */
int main(void) {
    int len; // Length of input
    char line[MAXLEN]; // The line of a string
    
    while ((len = my_getline(line, MAXLEN)) > 0) {
        if (line[0] != '\n') {
            remtrail(line, MAXLEN);
            printf("%s<--End of the character string.\n", line);
        }
    }

    return 0;
}

/* Read input for a string
 * of characters from the text
 * stream and store into
 * a character string
 */
int my_getline(char s[], int max) {
    int c, i; // Counter and the character entered
    
    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

void remtrail(char s[], int max) {
    int i; // Counter
    
    for (i = 0; i < max - 1 && s[i] != '\0'; ++i)
        ;
    
    for (i -= 1; s[i] == ' ' || s[i] == '\t' || s[i] == '\n'; --i)
        s[i] = '\0';
}
