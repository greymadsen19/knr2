#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1000

void my_getline(char str[], int lim);
int is_valid(char prev, char next);
void expand(char to[], char from[]);

/* Input shorthand notation
 * such as a-z or a-b-c
 * where characters of either
 * case are allowed and
 * digits are allowed
 * Expand the notation
 * into a full list
 * ex: abc....xyz
 */
int main(void) {
    char line[MAXLEN]; // Line to be entered
    char expanded[MAXLEN]; // Expanded notation

    printf("Enter a shorthand notation to be expanded (ex: a-z)\n");
    my_getline(line, MAXLEN);

    expand(expanded, line); // Expand the shorthand notation

    // Print expanded form
    printf("Expanded: %s", expanded);
    
    return 0;
}

/* Read input for characters
 * and store them in
 * a character string
 */
void my_getline(char str[], int lim) {
    int c, i; // Character and index

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        str[i] = c;

    if (c == '\n')
        str[i++] = c;

    str[i] = '\0';
}

/* Determine if the
 * notation is valid
 * IE: should only
 * contain alphabetic characters
 * of either case
 * or digits
 */
int is_valid(char prev, char next) {
    return prev < next && ((isdigit(prev) && isdigit(next)) ||
                           (isupper(prev) && isupper(next)) || (islower(prev) && islower(next)));
}

/* Expand shorthand
 * notation
 * by checking if a character
 * is a dash and there is no leading
 * dashes. If so calculate
 * the difference between p and n characters
 * where p is fstr[n - 1] and n is fstr[n + 1]
 * from that difference expand the notation
 * while incrementing a temp variable
 * until it reaches diff starting at 1
 * (indexed by one since the notation only expanded
 * and the original characters will be stored when there is no dash)
 * if there is a leading or trailing dash or the
 * range is invalid then treat the characters literally
 */
void expand(char to[], char from[]) {
    int i, j, k; // Counter variables

    int diff; // The difference of the two characters in the notation
    
    for (i = j = 0; from[i] != '\0'; ++i)
        // Check if there is no leading dash and if the notation is valid
        if (i != 0 && from[i] == '-' && is_valid(from[i - 1], from[i + 1])) {
            diff = from[i + 1] - from[i - 1];

            // Expand the notation
            for (k = 1; k < diff; ++k, ++j)
                to[j] = from[i - 1] + k;
        }
        else {
            to[j++] = from[i];
        }

    to[j] = '\0';
}
