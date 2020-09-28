#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 1000

int htoi(char str[]);
int my_getline(char str[], int len);

/* Read input for a hexadecimal
 * number and convert it
 * a decimal integer
 * where the 0x in the number
 * is optional
 */
int main(void) {
    int len; // Length of a line
    
    int decimal; // Decimal integer

    char hex[MAXLEN]; // Hexadecimal integer

    // Read input for a hexadecimal integer
    while ((len = my_getline(hex, MAXLEN)) > 0)
        decimal = htoi(hex); 

    printf("Number in Decimal: %d\n", decimal);

    return 0;
}

/* Read input for each character
 * and store them in a character string
 */
int my_getline(char s[], int max) {
    int c, i; // Character and subscript

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        if (c >= 'A' && c <= 'z')
            c = toupper(c);
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
} 

/* Convert the hex character
 * into decimal. If the character
 * is 0 - 9 then convert as (n - '0') * (16 * (16 * (16 * i)) 
 * where n is the character between 0 and 9 
 * n - '0' is the character minus 0 to convert from
 * ascii to an integer.
 * If the character is A-F then do the same except
 * n - 'A' is performed and 10 is added
 * since A-F = 10-15
 */
int htoi(char s[]) {
    int i; // Subscript

    int n; // number  count

    for (i = 0, n = -1; s[i] != '\n' && s[i] != '\0'; ++i)
        if (s[i] == '0' && s[i + 1] == 'X')
            ++i;
        else if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F'))
            ++n;

    int decimal = 0;

    for (i = 0; s[i] != '\0' && s[i] != '\n'; ++i) {
        if (s[i] == '0' && s[i + 1] == 'X') {
            ++i;
        }
        
        if (s[i] >= '0' && s[i] <= '9') {
            if (n == 0)
                decimal += (int) s[i] - '0';
            else 
                decimal += (int) (s[i] -'0') * (16 * n);

            --n;
        }
        else if (s[i] >= 'A' && s[i] <= 'F') {
            if (n == 0)
                decimal += (int) (s[i] - 'A') + 10;
            else
                decimal += (int) ((s[i] - 'A') + 10) * (16 * n);

            --n;
        }
    }

    return decimal; 
}
