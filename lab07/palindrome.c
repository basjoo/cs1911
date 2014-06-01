// Author: Danilo Scodellaro
// z3414551
// Date created: 16-APR-2014
// cs1911 lab07

// DESCRIPTION
// Program which reads in one string from the user and writes out the 
// characters one per line. 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 4097        // 4096 characters + '\0'
#define STRING_LENGTH_ADJUST 2      // Offset to make k the last 
                                    // character of string

int main(int argc, char const *argv[]) {

    // Initialise Variables
    char str[MAX_LINE_LENGTH];          // User input string
    int i;                              // For Loop counter ()
    int k;                              // Length of string
    int palindrome = 0;                 //  = 0 if palindrome, 1 if not

    // Request and read user input
    printf("Enter a string: ");
    fgets(str , MAX_LINE_LENGTH , stdin);

    // Loop to test if palindrome
    k = strlen(str) - STRING_LENGTH_ADJUST;
    for (i = 0; i <= k; ) {
        //printf(" i = %d, k = %d\n", i, k); //Useful for debugging
        if (str[i] != str[k]) {
            palindrome = 1;
        }
        i++;                            
        k--;
        
    }

    // Print Results
    if (palindrome == 0) {
        printf("String is a palindrome\n");
    } else {
        printf("String is not a palindrome\n");
    }

    return EXIT_SUCCESS;
}