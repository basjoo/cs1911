// Author: Danilo Scodellaro
// z3414551
// Date created: 13-MAY-2014
// cs1911
// Lab 10 - thousand.c

// DESCRIPTION
// program which when run creates a file named "1000.txt" 
// containing the first 1000 integers, one per line.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define START_NUM 1
#define END_NUM 1000

int main(int argc, char const *argv[]) {

    //Initialize Variables
    int i = 0;
    FILE * thousand = fopen ("1000.txt", "w");

    //Print integers to file
    for (i = START_NUM; i <= END_NUM; i++) {
        fprintf(thousand, "%d\n", i);
    }

    return EXIT_SUCCESS;
}