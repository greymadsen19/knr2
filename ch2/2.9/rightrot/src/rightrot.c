#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);

/* Set the value of
 * x an rotate it's bits
 * to the right n bit positions
 */
int main(void) {
    unsigned int x; // Value of x

    int n; // number of positions

    // Set x
    x = 0b01011100;

    // set n
    n = 6;

    printf("%u\n", rightrot(x, n));
    
    return 0;
}

/* RightRot:
 * rotate the bits
 * of x to the right by
 * n bit positions
 */
unsigned int rightrot(unsigned int x, int n) {
    return (x >> n) | (x << (32 - n));
}
