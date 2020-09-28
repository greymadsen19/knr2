#include <stdio.h>

#define MAXLEN  1000

int my_getline(char str[], int max);
void copy(char tostr[], char fromstr[]);

/* Read input from
 * a text stream into
 * an array of character
 * arrays. Determine the longest line
 * and display its line number
 */
int main(void) {
    int len; // Length of a line
    int max; // Highest length seeb
    char line[MAXLEN]; // current line
    char longest[MAXLEN]; // The longest line saved

    max = 0; // Initialize max to 0

    // Read input for a line return the length and determine
    // the line number of the longest line saving the line
    // into an array of the longest lines seen
    while ((len = my_getline(line, MAXLEN)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("Length of Longest line: %d\nContents: %s", max, longest);
    return 0;
}

/* Read input of a single character
 * until a newline character is seen
 * storing each character entered before the newline
 * if it is a newline store the escape sequence in the array
 * when the end of file is reached store a termination
 * character to signify the end of the character array
 */
int my_getline(char s[], int max) {
    int c, i; // Character entered and the counter variable

    // Read input for a character until max length is reached
    // or EOF is reached or  a newline is entered
    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    // Assign termination character to end of character string
    s[i] = '\0';

    return i;
}

/* Copy one character array
 * into another; While the character
 * is not \0 then assign from array to
 * to array
 */
void copy(char tostr[], char fromstr[]) {
    int i; // Counter variable
    
    i = 0;
    // Copy fromstr to tostr
    while ((tostr[i] = fromstr[i]) != '\0') 
        ++i;
}

