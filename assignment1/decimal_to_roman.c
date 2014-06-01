// Author: Danilo Scodellaro
// z3414551
// Date created: 16-APR-2014
// Date submitted: 05-MAY-2014
// cs1911
// Assignment 1 - Roman Numerals

// DESCRIPTION
// Program takes a decimal input from the user, and converts the number
// into its corresponding Roman Numeral.

// ASSUMPTIONS & CONSTRAINTS
// Only integers 1 - 3999 can be represented in Roman Numerals
// There is precisely one legal representation of any Roman Numeral
// Max input is 1024 characters
// Only the functions 'printf' and 'scanf' may be used

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_DECIMAL 3999      // Largest legal number in roman numerals
#define MIN_DECIMAL 1         // Lowest legal number in roman numerals
#define MAX_TIMES_RUN 1000000 // Loop entire program a max of x times

int main(int argc, char const *argv[]) {

    // Initialise Variables
    int decimal = 0;            // Decimal integer input by user
    int thousands = 0;          // # of thousands in the integer
    int hundreds = 0;           // # of hundreds in the integer
    int tens = 0;               // # of tens in the integer
    int ones = 0;               // # of ones in the integer
    int lifeline = 0;           // Variable to prevent infinite loops
    // Conversion arrays for matching decimal to roman    
    char romThousand[10][5] = 
        {"", "M", "MM", "MMM"};
    char romHundred[10][5] = 
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char romTen[10][5] = 
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char romOne[10][5] = 
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    //For loop so program runs multiple times, but not infinitely
    for(lifeline = 0; lifeline < MAX_TIMES_RUN; lifeline++) {

        // Request user input
        printf("Enter a decimal number: ");

        //Store user input
        if (scanf("%d", &decimal) != 1) {
            return EXIT_SUCCESS;
        }

        // Reject incompatible inputs
        if (decimal > MAX_DECIMAL || decimal < MIN_DECIMAL) {
            printf("%d can not be represented in Roman numerals.\n", decimal);
            continue;
        }

        // Determine # of Thousands
        thousands = decimal/1000;

        // Determine # of Hundreds
        hundreds = (decimal/100) - (thousands*10);

        // Determine # of Tens
        tens = (decimal/10) - (thousands*100) - (hundreds*10);

        // Determine # of Ones
        ones = decimal - (thousands*1000) - (hundreds*100) - (tens*10);

        // Print Results
        printf("%d is represented as %s%s%s%s in Roman numerals.\n", 
                decimal, romThousand[thousands], romHundred[hundreds],
                romTen[tens], romOne[ones] );
    }

    return EXIT_SUCCESS;
}