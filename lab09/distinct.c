// Author: Danilo Scodellaro
// z3414551
// Date created: 13-MAY-2014
// cs1911
// Lab 09 - distinct.c

// DESCRIPTION
// which given a single argument n reads lines from standard input 
// until n different lines have been read. Then prints a message 
// indicating how many lines were read

// ASSUMPTIONS
// Program is given a single positive integer as argument

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_LINE_LENGTH 128
#define MAX_LINES 1024

int main(int argc, const char *argv[]) {

    //Declare Variables
    int i = 0;                      // Loop counter
    int j = 0;                      // Loop counter
    char raw[MAX_LINES][MAX_LINE_LENGTH] = {{"\0"},{"\0"}}; // User input array
    int distinct = 0;               // No. of distinct lines detected
    int distinctA = 0;              // 0 if particular line has no matches, 
                                    // 1 otherwise
    int n = 0;                      // Int form of argument

    //Convert argument 1 from char to int
    n = atoi(argv[1]);

    //Store user input & determine no. of distinct
    for (i = 0; MAX_LINES; i++) {
        if (fgets(raw[i], MAX_LINE_LENGTH, stdin) == NULL) {
            break;
        }

        // Make distinct = 1 if only one input
        // This will return 0 distinct if no input
        if (i == 0) {
            distinct = distinct + 1;
        }
        for (j = 0; j < i; j++) {
            distinctA = 0;
            // Determines if any matches
            if (strcmp(raw[i], raw[j]) == 0) {
                distinctA = 0;
                break;
            } else {
                distinctA = 1;
            }
        }
        if (distinctA == 1) {
            distinct = distinct + 1;
        } 
        if (distinct == n) {
            i = i + 1;
            break;
        }
    }

    //Print to user
    printf("%d distinct lines seen after %d lines read.\n", distinct, i);

    return EXIT_SUCCESS;
}