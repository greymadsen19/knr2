#include <stdio.h>

int any(char s1[], char s2[]);

/* Store two character
 * strings and display
 * the position of the
 * first character that
 * is shared between the two
 * in s1
 */
int main(void) {
    char s1[] = "Top of Morning!";
    char s2[] = "My name is JackSepticeye!";

    int pos = any(s1, s2);

    printf("Position of first matching character: %d\n", pos);
    printf("Character at position %d: %c\n", pos, s1[pos]); 
    return 0;
} 

/* Any Function:
 * Return the position
 * of the first character
 * in s1 that matches any character in s2
 */
int any(char s1[], char s2[]) {
    int i, j; // Subscript

    for (i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j])
                return i; 
        }
    }

    return -1;
}
