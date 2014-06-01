// Author: Danilo Scodellaro
// Date created: 12-APR-2014
// cs1911 lab06
// DESCRIPTION
// Program  reads a vector of 10 integers then prints the minimum, 
// maximum & mean of the integers

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 10

int main(int argc, char const *argv[]) {
    int vector[SIZE];   // 1D array of 10 integers
    int minimum;        // Smallest integer of the array
    int maximum;        // Largest vector of the array
    float total = 0;    // Sum of all integers in array
    float mean;         // Average of vectors
    int i, j;     // Loop counters      

    printf("Enter vector of 10 numbers: ");
    // Loop to input integers into array
    for ( i = 0; i < SIZE; i = i + 1) {
        if (scanf("%d", &vector[i]) == 0) {
            printf("Sorry I couldn't read enough numbers\n");
            return EXIT_FAILURE;
        }
    }
    
    // Set min and max to first integer of array to make loop work
    minimum = vector[0];
    maximum = vector[0];

    // Loop to determine minimum, maximum and total values
    for ( j = 0; j < SIZE; j = j + 1) {
        if (vector[j] < minimum) {
            minimum = vector[j];
        }
        if (vector[j] > maximum) {
            maximum = vector[j];
        }
        total = total + vector[j];
    }

    // Determine mean of array
    mean = (total / SIZE);

    // Print vector statistics
    printf("Minimum vector value is %d\n", minimum);
    printf("Maximum vector value is %d\n", maximum);
    printf("Average vector values is %.1f\n", mean);

    return EXIT_SUCCESS;
}