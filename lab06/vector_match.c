// Author: Danilo Scodellaro
// Date created: 12-APR-2014
// cs1911 lab06

// DESCRIPTION
// Program that reads 2 vectors of 10 positive integers the prints a 
// count of how many times the 2 vectors have the same value in the 
// same position.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 10

int main(int argc, char const *argv[]) {
    // Initialise Variables
    int vector1[SIZE];      // 1st Array of positive numbers
    int vector2[SIZE];      // 2nd Array of positive numbers
    int match = 0;          // # of matches
    int i, k, l;               // Loop counters

    // Loop to input numbers into vectors 1 & 2
    printf("Enter vector 1 of 10 positive numbers: ");
    for ( i = 0; i < SIZE; i++) {
        if (scanf("%d", &vector1[i]) == 0) {
            printf("Sorry I couldn't read enough numbers\n");
            return EXIT_FAILURE;
        }
    }
    printf("Enter vector 2 of 10 positive numbers: ");
    for ( k = 0; k < SIZE; k++) {
        if (scanf("%d", &vector2[k]) == 0) {
            printf("Sorry I couldn't read enough numbers\n");
            return EXIT_FAILURE;
        }
    }

    for ( l = 0; l < SIZE; l++) {
        if (vector1[l] == vector2[l]) {
            match = match + 1;
        }
    }

    // Print results
    printf("Vectors match in %d positions.\n", match);

    return EXIT_SUCCESS;
}