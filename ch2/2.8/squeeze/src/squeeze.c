#include <stdio.h>

void squeeze(char s1[], char s2[]);

/* Store two character
 * strings and compare them if
 * s2[i] equals the character in
 * s1[i] then remove that character
 * from s1
 */
int main(void) {
    char s1[] = "Hello, World! My name is Dallas!";
    char s2[] = "Hello, World!";

    printf("Original: %s\n", s1);

    squeeze(s1, s2);

    printf("Squeezed: %s\n", s1);

    return 0;
}

/* Squeeze Function:
 * compare two strings
 * if the characters are the same
 * remove the character
 * from s1
 */
void squeeze(char s1[], char s2[]) {
    int i, j, k;

    int match;

    for (i = 0, j = 0; s1[i] != '\0'; i++) {
        match = 0;
        for (k = 0; s2[k] != '\0' && !match; k++) {
            if (s2[k] == s1[i])
                match = 1;
        }

        if (!match)
            s1[j++] = s1[i];
    }

    s1[j] = '\0';
}
