// Author: Danilo Scodellaro
// Date created: 12-APR-2014
// cs1911 lab06

// DESCRIPTION
// Program that reads 2 vectors of 10 positive integers the prints a 
// count of how many times the 2 vectors have the same value in the 
// same position, and how many times the vectors have the same value 
// but in a different position.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 10

int main(int argc, char const *argv[]) {
    
    // Initialise Variables
    int vector1[SIZE] = {0};      // 1st Array of positive numbers
    int vector2[SIZE] = {0};      // 2nd Array of positive numbers
    int match = 0;          // # of matches
    int mismatch = 0;       // # of mismatches (same value, diff pos.)
    int i = 0;           // Loop counters
    int j = 0;

    // Loop to input numbers into vectors 1 & 2
    printf("Enter vector 1 of 10 positive numbers: ");
    for ( i = 0; i < SIZE; i++) {
        if (scanf("%d", &vector1[i]) == 0) {
            printf("Sorry I couldn't read enough numbers\n");
            return EXIT_FAILURE;
        }
    }
    printf("Enter vector 2 of 10 positive numbers: ");
    for ( i = 0; i < SIZE; i++) {
        if (scanf("%d", &vector2[i]) == 0) {
            printf("Sorry I couldn't read enough numbers\n");
            return EXIT_FAILURE;
        }
    }

    // Loop to check for matches
    for (i = 0; i < SIZE; i++) {
        if (vector1[i] == vector2[i]) {
            match = match + 1;
            vector1[i] = 0;
            vector2[i] = 0;
        }
    }

    //Loop to check for mismatches
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (vector1[i] == vector2[j] && vector1[i] != 0 && vector2[j] != 0) {
                mismatch = mismatch + 1;
                vector1[i] = 0;
                vector2[j] = 0;
            }
        }
    }

    //DISCLAIMER
    // This mismatch method is a cheat. It 'deletes' integers by turning them 
    // into zeros. Because the task specification states that only positive
    // integers will be entered, I could have simple 'deleted' to a negative
    // number (or a floating-point number), but zero is neat and fulfills
    // the dryrun testing.

    // Print results
    printf("Vectors match in %d positions.\n", match);
    printf("Vectors mismatch in %d positions.\n", mismatch);

    return EXIT_SUCCESS;
}