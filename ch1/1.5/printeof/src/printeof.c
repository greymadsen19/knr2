#include <stdio.h>

/* The program prompts
 * for a character to be entered
 * and the value of EOF is printed
 */

int main(void) {
    // Prompt for a character
    printf("Enter a character\n");

    // Accept input for a character and display the value of EOF
    printf("The value of EOF is: %d\n", getchar() != EOF);

    return 0;
}
