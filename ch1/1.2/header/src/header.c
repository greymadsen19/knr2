#include <stdio.h>

/* Display a conversion table for
 * temperature from Farhenheit to Celsius
 * until farhenheit reaches 300 °F starting at 0 °F
 * incrementing by 20 degrees.
 * to convert Fahrenheit to Celsius
 * the formula C= (°F -32.00) * (5.00/9.00)
 * is used. Before this is displayed, first a
 * header of the table is displayed.
 */

int main(void) {
    float fahr,celsius; // The temperature values

    // The boundary values
    int lower = 0;
    int upper = 300;

    // counter variable
    int step = 20;

    fahr = lower; // initialize fahrenheit

    // Display a header for the table
    printf("Fahrenheit-Celsius Converion\n");

    // Create a while loop to print the temperature
    // in fahrenheit and celsius until fahr reaches 300
    while (fahr <= 300) {
        // Convert to celsius
        celsius = (fahr - 32.0) * (5.0 / 9.0);

        // Display the table
        // 0   -17.8
        printf("%6.0f %16.1f\n", fahr, celsius);

        // Increment fahr by 20
        fahr += step;
    }

    return 0;
}
