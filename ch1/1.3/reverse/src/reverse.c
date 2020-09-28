#include <stdio.h>

/* Display a table of temperature
 * conversions from Fahrenheit to Celius
 * in reverse order
 */

int main(void){
    float celsius; // The celsius variable

    int fahr; // Fahrenheit temperature

    // Decrement farh by 20 starting at 3000
    // until it reaches 0
    for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
        // Calculate celsius
        celsius = (fahr - 32.0) * (5.0 / 9.0);

        // Display the conversions
        printf("%3d %6.1f\n", fahr, celsius);
    }

    return 0;
}
