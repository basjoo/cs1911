// Author: Danilo Scodellaro
// z3414551
// Date created: 16-APR-2014
// cs1911 lab07

// DESCRIPTION
// Program which reads characters from its input and writes the same 
// characters to its output, except it does not write lower case 
// vowels ('a', 'e', 'i', 'o', 'u').

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#define VOWEL ('a' || 'e' || 'i' || 'o' || 'u')

int main(int argc, char const *argv[]) {

    //Initialise Variables
    char c = getchar();                     //Character input
               
    //Loop to test if each character is a vowel, only print consonant
    for ( ; c != EOF ; ) { 
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            putchar(c);
        }
        c = getchar();
    }

    return EXIT_SUCCESS;
}