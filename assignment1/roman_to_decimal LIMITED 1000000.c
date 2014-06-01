// Author: Danilo Scodellaro
// z3414551
// Date created: 25-APR-2014
// Date submitted: 05-MAY-2014
// cs1911
// Assignment 1 - Roman Numerals

// DESCRIPTION
// Program takes a roman numeral input from the user, and converts the 
// input into its corresponding Decimal Digit.

// ASSUMPTIONS & CONSTRAINTS
// Only integers 1 - 3999 can be represented in Roman Numerals
// There is precisely one legal representation of any Roman Numeral
// Max input is 1024 characters
// Any function within the standard C library may be used

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#define MAX_DECIMAL 3999      // Largest legal number in roman numerals
#define MIN_DECIMAL 1         // Lowest legal number in roman numerals
#define MAX_TIMES_RUN 1000000 // Loop entire program a max of x times
#define MAX_LINE_LENGTH 1024  // Maximum allowed line length

int makeDecimal (char roman[MAX_LINE_LENGTH]);

int main(int argc, char const *argv[]) {

    // Initialise Variables
    int decimal = 0;             // Decimal integer output by program
    int lifeline = 0;            // Variable to prevent infinite loops
    int i = 0;                   // loop counter
    int j = 0;                   // loop counter
    int rawLength = 0;           // Length of raw string
    int thousands = 0;           // # of thousands in the integer
    int hundreds = 0;            // # of hundreds in the integer
    int tens = 0;                // # of tens in the integer
    int ones = 0;                // # of ones in the integer
    char roman[MAX_LINE_LENGTH]; // User input without spaces
    char raw[MAX_LINE_LENGTH];   // Raw user input    
    char test[MAX_LINE_LENGTH];  // Back conversion of decimal to Roman 
    // Conversion arrays for matching decimal to roman
    char romThousand[10][5] = 
        {"", "M", "MM", "MMM"};
    char romHundred[10][5] = 
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char romTen[10][5] = 
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char romOne[10][5] = 
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    // For loop so program runs multiple times, but not infinitely
    for(lifeline = 0; lifeline < MAX_TIMES_RUN; lifeline++) {

        // Request user input
        printf("Enter a number in Roman numerals: ");

        // Store user input
        if (fgets(raw, MAX_LINE_LENGTH, stdin) == NULL) {
            return EXIT_SUCCESS;
        }

        // Reiterate loop if no input (user pressed enter)
        if (raw[0] == '\n') {
            continue;
        }

        // Determine length of raw string
        rawLength = strlen(raw);

        // Loop to convert all characters to uppercase
        for (i = 0; i <= rawLength; i++) {
            raw[i] = toupper(raw[i]);
        }     

        // Loop to eliminate non-letter characters
        for (i = 0, j = 0; i < rawLength; i++) {
            if (raw[i] >= 'A' && raw[i] <= 'Z') {
                roman[j] = raw[i];
                j++;
            }
        }
        roman[j] = '\0';
        
        // Call the Decimal function
        decimal = makeDecimal(roman);

        // Back conversion of decimal into test (decimal back to Roman)
        thousands = decimal/1000;
        hundreds = (decimal/100) - (thousands*10);
        tens = (decimal/10) - (thousands*100) - (hundreds*10);
        ones = decimal - (thousands*1000) - (hundreds*100) - (tens*10);

        sprintf(test, "%s%s%s%s", romThousand[thousands], 
                romHundred[hundreds], romTen[tens], romOne[ones]);

        // Check if roman numerals are in illegal order (e.g. IVI != 5)
        if (strcmp(roman, test) != 0) {
            printf("Not a valid number in Roman numerals.\n");
            continue;
        }

        // Reject out of range inputs
        if (decimal > MAX_DECIMAL || decimal < MIN_DECIMAL) {
            printf("Not a valid number in Roman numerals.\n");
            continue;
        }

        // Print Results
        printf("%s in Roman numerals is %d in decimal.\n", roman, decimal);
    }

    return EXIT_SUCCESS;
}

int makeDecimal (char roman[MAX_LINE_LENGTH]) {

    // Initialise Variables
    int romanLength = 0;         // Length of roman string
    int i = 0;                   // loop counter
    int decimal = 0;             // Decimal integer output by program

    // Determine length of roman string
    romanLength = strlen(roman);

    // Determine decimal output            
    for (i = 0, decimal = 0; i < romanLength; i++) {
        if (roman[i] == 'I' && roman[i+1] != 'V' && roman[i+1] != 'X') {
            decimal = decimal + 1;
        } else if (roman[i] == 'I' && roman[i+1] == 'V') {
            decimal = decimal + 4;
            i = i + 1; 
        } else if (roman[i] == 'I' && roman[i+1] == 'X') {
            decimal = decimal + 9;
            i = i + 1;
        } else if (roman[i] == 'V') {
            decimal = decimal + 5;
        } else if (roman[i] == 'X' && roman[i+1] != 'L' && roman[i+1] != 'C') {
            decimal = decimal + 10;
        } else if (roman[i] == 'X' && roman[i+1] == 'L') {
            decimal = decimal + 40;
            i = i + 1;
        } else if (roman[i] == 'X' && roman[i+1] == 'C') {
            decimal = decimal + 90;
            i = i + 1;
        } else if (roman[i] == 'L') {
            decimal = decimal + 50;
        } else if (roman[i] == 'C' && roman[i+1] != 'D' && roman[1+i] != 'M') {
            decimal = decimal + 100;
        } else if (roman[i] == 'C' && roman[i+1] == 'D') {
            decimal = decimal + 400;
            i = i + 1;
        } else if (roman[i] == 'C' && roman[i+1] == 'M') {
            decimal = decimal + 900;
            i = i + 1;
        } else if (roman[i] == 'D') {
            decimal = decimal + 500;
        } else if (roman[i] == 'M') {
            decimal = decimal + 1000;
        }
    }
    return decimal;
}