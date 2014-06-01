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

#define MAX_LINE_LENGTH 1024

int main(int argc, char const *argv[]) {

    //Initialise Variables
    char str[MAX_LINE_LENGTH];          //User input string
    int i;                              //For Loop counter ()

    //Request and read user input
    printf("Enter a string: ");
    fgets(str , MAX_LINE_LENGTH , stdin);

    //Loop to print out each character of string on a new line
    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        putchar(str[i]);
        putchar('\n');
    }

    return EXIT_SUCCESS;
}