#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);

/* Set the value for x
 * and invert the n bits
 * starting at p and
 * displaye the result
 */
int main(void) {
    unsigned int x; // X value
    
    int p, n; // Position and number of bits

    // Set x
    x = 0x4E4C4;

    // Set position
    p = 4;

    // Set number of bits
    n = 4;

    printf("%u\n", invert(x, p, n));

    return 0;
}

/* Invert: Set x
 * to n bits starting
 * at position p where
 * the bits are inverted
 */
unsigned int invert(unsigned int x, int p, int n) {
    return x ^ (~(~0 << n) << (p + 1 - n));
}
