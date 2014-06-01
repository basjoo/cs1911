// Author: Danilo Scodellaro
// z3414551
// Date created: 16-APR-2014
// cs1911 lab07

// DESCRIPTION
// Modified 'palindrome.c' program so characters which are not letters
// are ignored and difference between upper case and lower case are 
// ignored.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 4097        // 4096 characters + '\0'
#define STRING_LENGTH_ADJUST 1      // Offset to make k the last 
                                    // character of string

//Note that the string_length_adjust changed from 2 to 1 in this program

int main(int argc, char const *argv[]) {

    // Initialise Variables
    char str[MAX_LINE_LENGTH];        // User input string
    int i;                            // For Loop counter ()
    int k = 0;                        // Length of string
    int palindrome = 0;               //  = 0 if palindrome, 1 if not
    char trim[MAX_LINE_LENGTH];
    int j = 0;

    // Request and read user input
    printf("Enter a string: ");
    fgets(str , MAX_LINE_LENGTH , stdin);
    //puts(str);                            //Useful for debugging

    // Loop to convert all characters to lowercase
    k = strlen(str);
    for (i = 0; i <= k; i++) {
        str[i] = tolower(str[i]);
    }
    //puts(str);                            //Useful for debugging

    // Loop to eliminate non-letter characters
    k = strlen(str);
    for (i = 0; i <= k; ) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            trim[j] = str[i];
            j++;
        }
        if (i == (k-1)) {
            trim[j] = '\0';
        }
        i++;
    }
    //puts(trim);                            //Useful for debugging

    // Loop to test if palindrome
    k = strlen(trim) - STRING_LENGTH_ADJUST;
    for (j = 0; j <= k; ) {
        //printf(" j = %d, k = %d\n", j, k); //Useful for debugging
        if (trim[j] != trim[k]) {
            palindrome = 1;
        }
        j++;                            
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