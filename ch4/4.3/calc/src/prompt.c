#include <stdio.h>

/* Display the name of the calculator
 * and explain the notation of the
 * calculator and then prompt the use
 * user what to enter to see the
 * various commands
 */
void prompt(void) {
	printf("                     Reverse Polish Notation Calculator\n");
	printf("        A calculator that uses a mathematical notation called PostFix\n");
	printf("        in which the operators are placed after the operands I.E: 2 5 /, 2 sqrt\n");
	printf("     As such, this calculator also allows the declaration of variables 'A' - 'Z'\n");
	printf("        as well as various commands that extend beyond simple arithmetic\n");
	printf("        to see a list of these commands press ? or press <CTRL>+D to quit.\n");
}
