#include <stdio.h>

int bitcount(unsigned int x);

/* Bitcount:
 * In a two's complementary
 * number system, x &= (x - 1) deletes the right
 * most 1-bit in x. Explain why. Use this
 * observation to make a faster version
 * of bitcount.
 */
int main(void) {
    unsigned int x; // X value

    x = 0b01100111; // Set x

    /* x &= (x - 1)
     * deletes the rightmost
     * 1-bit because if the number is
     * odd doing x - 1 would set the right
     * most bit two zero making x & (x - 1)
     * set the bit to zero since both bits
     * would be different. If it is even (x - 1)
     * would set the rightmost 1-bit to zero and
     * all of the following 0-bits to 1 making
     * the bits different than that of x
     * therefore all of the altered bits result in
     * zero when the AND operation is performed
     * Example:
     * 0b10110010 & (0b10110010 - 0b00000001) =
     * 0b10110010 & 
     * 0b10110001 =
     * 0b10110000
     */

     printf("Number of 1-bits: %d\n", bitcount(x));

     return 0;
}

/* Using this observation
 * use x &= (x - 1)
 * to create a faster
 * bitcount
 */
int bitcount(unsigned int x) {
    int b; // Number of 1-bits

    for (b = 0; x != 0; x &= (x - 1))
        ++b;

    return b;
}
