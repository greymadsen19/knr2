#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Print the ranges
 * of the various
 * integer datatypes
 * both signed and unsigned.
 * Then print the ranges of
 * the single-precision and
 * double-precision floating-point
 * data types
 */
int main(void) {
    // Print range of signed char
    printf("Range of Signed Char: %i - %i\n", CHAR_MIN, CHAR_MAX);

    // print range of unsigned char
    printf("Range of Unsigned Char: 0 - %u\n",  UCHAR_MAX);

    // print range of signed short int
    printf("Range of Signed Short Int: %i - %i\n", SHRT_MIN, SHRT_MAX);

    // print range of unsigned short int
    printf("Range of Unsigned Short Int: 0 - %u\n", USHRT_MAX);

    // print range of signed int
    printf("Range of Signed Int: %i - %i\n", INT_MIN, INT_MAX);
    
    // print range of unsigned int
    printf("Range of Unsigned Int: 0 - %u\n", UINT_MAX);

    // print range of signed long int
    printf("Range of Signed Long Int: %li - %li\n", LONG_MIN, LONG_MAX);

    // print range of unsigned long int
    printf("Range of Unsigned Long Int: 0 - %lu\n", ULONG_MAX);

    // print range of single-precision floating-point
    printf("Range of Single-Precision Floating-Point: %e - %e\n", FLT_MIN, FLT_MAX);

    // print range of double-precision floating-point
    printf("Range of Double-Precision Floating-Point: %e - %e\n", DBL_MIN, DBL_MAX);
    return 0;
}
