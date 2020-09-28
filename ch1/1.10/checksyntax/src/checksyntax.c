#include <stdio.h>

#define MAXLEN 1000

int my_getline(char str[], int len);

/* This program accepts input for
 * another program and checks for syntax
 * errors in the program
 * if there are errors each one is displayed
 * else the program states there are no
 * errors
 */
int main(void) {
    int len; // Length of a line
    int n; // Counter
   
    char line[MAXLEN]; // Current line

    int brace, bracket, parentheses; // Types of brackets

    int s_quote, d_quote; // Quotes

    // To Track previous and next characters
    // and determine if it is single line
    // or in a multiline comment
    int prev, next, mult_line_com, sin_line_com;

    int escaped, errors; // Determine if escape and track errors

    escaped = errors = 0;

    brace = bracket = parentheses = 0; // Initialize brackets

    s_quote = d_quote = 0; // Initialize quotes 
    

    mult_line_com = sin_line_com = 0; // Initialize comments 

    while ((len = my_getline(line, MAXLEN)) > 0) {
        for (n = 0; line[n] != '\0'; ++n) {
   
            // Track previous and next character
            prev = n - 1;
            next = n + 1;
            
            if (line[prev] == '\\')
                escaped = 1;

            // Check for inline comment
            if (line[prev] == '/' && line[n] == '/' && !sin_line_com) {
                sin_line_com = 1;
            }
            
            // Check for a newline to terminate the single line comment
            if (line[n] == '\n' && sin_line_com)
                sin_line_com = 0;

            // Check for other syntax errors if there isn't a single line comment
            if (!sin_line_com && !escaped) {
                // Check for opening comment
                if (line[n] == '/' && line[next] == '*' && !mult_line_com) {
                    mult_line_com = 1; 
                    errors = 1;
                }

                // Check for closing comments
                if (line[prev] == '*' && line[n] == '/' && mult_line_com) {
                    mult_line_com = 0;
                    errors = 0; 
                }

                if (!mult_line_com && !escaped) {

                    // Check if there is already a brace
                    // If not determine if the braces are matched
                    if (line[n] == '{' && brace && !d_quote)
                        ++brace;
                    else if (line[n] == '{' && !brace && !d_quote)
                        ++brace; 
                    else if (line[n] == '}' && !brace && !d_quote)
                        errors = 1; 
                    else if (line[n] == '}' && brace) {
                        --brace;
                        errors = 0;
                    }

                    // Determine if double quotes match
                    if (line[n] == '"' && d_quote) {
                        d_quote = 0;
                        errors = 0;
                    }
                    else if (line[n] == '"' && !d_quote)
                        ++d_quote;
                    else if (line[n] == '\n' && d_quote)
                        ++d_quote;
                   
                    // Check single quotes as well
                    if (line[n] == '\'' && s_quote && !d_quote) {
                        s_quote = 0;
                        errors = 0;
                    }
                    else if (line[n] == '\'' && !s_quote && !d_quote)
                        ++s_quote;
                    else if (line[n] == '\n' && s_quote)
                        ++s_quote;

                    // Check for matching parentheses
                   if (line[n] == '(' && !d_quote)
                       ++parentheses;
                   else if (line[n] == ')' && !d_quote)
                      ++parentheses;
                   else if (line[n] == '\n' && (parentheses % 2) == 0) {
                       parentheses = 0;
                       errors = 0;
                   }

                   if (line[n] == '[' && !d_quote)
                       ++bracket;
                   else if (line[n] == ']' && !d_quote)
                       ++bracket;
                   else if (line[n] == '\n' && (bracket % 2) == 0) {
                       bracket = 0;
                       errors = 0;
                   }

                   // Check if there are errors and change the flag
                   if (s_quote > 0 || d_quote > 0 || 
                       parentheses > 0 || bracket > 0 || brace > 0)
                       errors = 1; 
                }
            }
        }
    }

    // Display error messsage if there are any
    // Or state that there were no errors 
    if (errors) {
        if (mult_line_com)
            printf("Error! Unbalanced Comments!\n"); 
        if (brace > 0)
            printf("Error! Unbalanced Braces!\n");
        if (bracket > 0)
            printf("Error! Unbalanced Brackets!\n");
        if (parentheses > 0)
            printf("Error! Unbalanced Parentheses!\n");
        if (d_quote > 0)
            printf("Error! Unbalanced Double Quotes!\n");
        if (s_quote > 0)
            printf("Error! Unbalanced Single Quotes!\n");
    }
    else {
        printf("There are no syntax errors found!\n");
    }
    
    return 0;    
}

/* Read input for each individual
 * character and store them into 
 * a character string
 */
int my_getline(char s[], int max) {
    int c, i; // Character and subscript

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}
