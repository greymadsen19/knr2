#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

void itoa(unsigned int n, char str[]);
void reverse(char str[]);


/* In a two's complementary system
 * a signed integer has a range
 * from -(2^(wordsize - 1) - > (2^(wordsize - 1)
 * This results in the max wordsize of a positive integer
 * being 1 less than the max wordsize of a negative integer.
 * becausse the most significant bit is the sign bit
 * so that a negative integer has the left most bit
 * set to 1 to represent the sign because of this if you
 * add 1 to a positive integer equal to its max wordsize - 1
 * then it would cause an integer overflow where it would be
 * negative but hold that value. For example: An 8-bit
 * signed integer has a max positve value of 127 or 01111111
 * and a max negative value of -128 10000000.
 * As a result of the left most significant bit used as the
 * sign bit, positive integers will be 1 less than than
 * a negative integer meaning that an 8-bit signed integer
 * with the the value of 128 would cause an integer overflow
 * and be flipped to negative (-128). This error can be resolved
 * by using an unsigned integer in which an 8-bit integer
 * would have a range of 0 to 255 or 00000000 to 11111111
 */
int main(void) {
    char line[MAXLEN]; // String to store converted characters

    unsigned int num; // number to be entered

    num = 128;
    
    itoa(num, line);

    printf("Converted into characters: %s\n", line);
    
    return 0;
}

/* Convert an integer to
 * its character representation
 * in a character string.
 * considering that a signed positive
 * integer would cause an integer overflow
 * if 2^wordsize - 1 is reached IE: in
 * an 8-bit integer 128 would flip to -128
 * An unsigned integer will be used instead
 */
void itoa(unsigned int n, char str[]) {
    int i;

    i = 0;
    
    do {
        str[i++] = n % 10 + '0'; // Get the next digit (in base-10 representation; n % 10 would take the digit at that index)
    } while (( n /= 10) > 0); // n /= 10 deletes the right-most digit in an integer as a result of truncation

    str[i] = '\0';
    
    // Reverse the string so that it is in the order the integers are entered
    reverse(str);
}

/* Reverse a string
 * by looping over the characters
 * and decrementing a variable j
 * until i is less than j
 * and tracking the character to
 * store the character at j at i
 * the replacing the character at i
 * with the character
 */
void reverse(char str[]) {
    int c, i, j; // The character and counters

    // Reverse the string
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}
