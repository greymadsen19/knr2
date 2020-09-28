#include <stdio.h>

/*
 * Starting from 0
 * convert temperatures
 * in fahrenheit for every 20
 * degrees into celsius
 * where C = (F - 32) * (5 / 9)
 * and print a table of the
 * conversions.
 */
float convert(float fahr);

int main(void) {
    float fahr, celsius; // Fahrenheit temperature and celsius

    // Convert to celsius and print the table of values
    for (fahr = 0; fahr <= 300; fahr += 20) {
        celsius = convert(fahr);

        // Display the results
        printf("%3.0f°F %6.1f°C\n", fahr, celsius);
    }

    return 0;
}

/* Taking the temperature
 * in fahrenheit convert
 * to celsius
 * by calculating C = (F - 32) * (5 / 9)
 */
float convert(float fahr) {
    return (fahr - 32.0f) * (5.0f / 9.0f);
}
