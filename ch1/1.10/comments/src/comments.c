#include <stdio.h>

#define MAXLEN 1000
#define IN 1
#define OUT 0

int my_getline(char str[], int len);
void rem_comments(char to[], char from[]);

/* Read input for a 
 * a program checking for
 * comments. Remove all comments
 * from the program, if there are
 * quotes in the comments
 * or character constants remove those
 * as well if they are part of the comment
*/
int main(void) {
    int len; // Length of a line

    char line[MAXLEN]; // Current line
    char remcomments[MAXLEN]; // Removed comments

    // Read input for a line of characters
    while ((len = my_getline(line, MAXLEN)) > 0) {
        rem_comments(remcomments, line);
        printf("%s", remcomments);
    }
    
    return 0;
}

/* Read in each individual character
 * of a character string and
 * store them into an array
 */
int my_getline(char s[], int max) {
    int c, i; // Character and subscript

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    } 

    s[i] = '\0';

    return i;
}

/* Check each character in
 * a program for comments or
 * quotes. If the line is part of
 * a comment or there are quotes in th
 * comment then ignore them.
 * else store a copy of the character
 * string ignoring the comments of
 * the program
 */
void rem_comments(char to[], char from[]) {
    int incomment, inquote; // To determine if it is a comment

    char c; // The character in the string

    int i, n; // Counters

    // Initialize flags
    incomment = inquote = OUT;

    // initialize counters
    i = n = 0;

    while (( c = from[i]) != '\0') {
       if (from[n] == '"')
           inquote = IN; 

       if (!inquote) {
           if (from[n] == '/' && from[n + 1] == '*') {
               n += 2;
               incomment = IN;
           }
           
           if (from[n] == '/' && from[n + 1] == '*') {
               n += 2;
               incomment = OUT;
           }
           
           if (incomment) {
               ++n;
           }
           else {
               to[i] = c;
           }
       }
       else {
           ++n;
           to[i] = c;
       }
       
       ++i;
    }

    to[i] = '\0';    
}
