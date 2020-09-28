#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

/* Set the values of x and y
 * and display the result of setting
 * x with n bits (using a bitmask) beginning
 * at position p and set to the rightmost n bits
 * of y
 */
int main(void) {
    unsigned int x, y; // X and Y

    int p, n; // Position and number of bits

    // set x
    x = 0xEA25FE81;

    // set y
    y = 0xFE6A;

    // Set starting position
    p = 4;

    // set number of bits
    n = 4;

    printf("%u\n", setbits(x, p, n, y));

    return 0;
}

/* Setbits: set x to the n bits
 * using a bitmask that begins at
 * position p and is set to the rightmost n bits
 * of y
 */
unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
    int x_mask = ~((~0 << n) << (p + 1 - n));
    int y_mask = ~(~0 << n);
    int y_shift = (p + 1 - n);
    
    return (x & x_mask) | (y & y_mask) << y_shift; 
}
