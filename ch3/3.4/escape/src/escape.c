#include <stdio.h>

#define MAXLEN 1000

int my_getline(char s[], int max);
void escape(char s[], char t[]);
void unescape(char s[], char t[]);

/* Read input for a character
 * string and convert escape
 * characters into their visible
 * counterparts. Also convert
 * visible escapes into
 * real characters
 */
int main(void) {
    int len; // Length of a line
    
    char original[MAXLEN]; // Original line
    char escaped[MAXLEN]; // Escaped line

    while ((len = my_getline(original, MAXLEN)) > 0) {
        escape(escaped, original);
        printf("%s\n", escaped);
        
        unescape(escaped, original);
        printf("%s\n", escaped);
    }

    return 0;
}

/* Read input for characters
 * from the keyboard
 * and store them into
 * a character array
 */
int my_getline(char str[], int max) {
    int c, i; // Character and index

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        str[i] = c;

    if (c == '\n') {
        str[i] = c;
        ++i;
    }

    str[i] = '\0';

    return i;
}

/* Copy a string into another checking
 * for escaped characters
 * and turn them into their
 * visual counterparts
 */
void escape(char to[], char from[]) {
    int i, j; // Initialize a counter variable

    i = j = 0;

    while (from[i] != '\0') {
        switch (from[i]) {
        case '\n':
            to[j] = '\\';
            to[++j] = 'n';
            break;
        case '\t':
            to[j] = '\\';
            to[++j] = 't';
            break;
        case '\v':
            to[j] = '\\';
            to[++j] = 'v';
            break;
        case '\b':
            to[j] = '\\';
            to[++j] = 'b';
            break;
        case '\r':
            to[j] = '\\';
            to[++j] = 'r';
            break;
        case '\f':
            to[j] = '\\';
            to[++j] = 'f';
            break;
        case '\a':
            to[j] = '\\';
            to[++j] = 'a';
            break;
        case '\\':
            to[j] = '\\';
            to[++j] = '\\';
            break;
        case '\?':
            to[j] = '\\';
            to[++j] = '?';
            break;
        case '\'':
            to[j] = '\\';
            to[++j] = '\'';
            break;
        case '\"':
            to[j] = '\\';
            to[++j] = '"';
            break;
        default:
            to[j] = from[i];
            break;
        }
 
        ++i;
        ++j;
    }

    // Terminate new character string
    to[j] = from[i];
}

/* Copy a string into another
 * checking for visible
 * escape sequences and turn
 * them into actual escape characters
 */
void unescape(char to[], char from[]) {
    int i, j; // The counters

    i = j = 0;

    while (from[i] != '\0') {
        switch (from[i]) {
        case '\\':
            switch (from[++i]) {
            case 'n':
                to[j] = '\n';
                break;
            case 't':
                to[j] = '\t';
                break;
            case '\v':
                to[j] = '\v';
                break;
            case 'b':
                to[j] = '\b';
                break;
            case 'r':
                to[j] = '\r';
                break;
            case 'f':
                to[j] = '\f';
                break;
            case 'a':
                to[j] = '\a';
                break;
            case '\\':
                to[j] = '\\';
                break;
            case '?':
                to[j] = '\?';
                break;
            case '\'':
                to[j] ='\'';
                break;
            case '\"':
                to[j] = '\"';
                break;
            default:
                to[j++] = '\\';
                to[j] = from[i];
                break;
            }
            break;
        default:
            to[j] = from[i];
            break;
        }
        ++i;
        ++j;
    }

    to[j] = from[i];
}
