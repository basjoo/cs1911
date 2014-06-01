// Author: Danilo Scodellaro
// z3414551
// Date created: 13-MAY-2014
// cs1911
// Lab 10 - numbers.c

// DESCRIPTION
// program generalizes the program in the previous exercise. Its 
// should take 3 arguments. The first & second arguments will 
// specify the range of integers to be placed in the file. The 
// third argument will specify the file to be created.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ARGUMENT_COUNT 3

int main(int argc, char const *argv[]) {

    //Initialize Variables
    int i = 0;
    int lower = atoi(argv[1]);
    int upper = atoi(argv[2]);
    FILE *output;

    //Error Reporting for invalid argument count
    if (argc != ARGUMENT_COUNT + 1) {
    	fprintf(stderr, "Not enough arguments\n"
    					"Please enter 3 arguments\n"
    					"lower, upper, output\n");
    }

    //Create output file
    //fprintf(stderr, "Creating %s ...\n", argv[3]);
    if ((output = fopen (argv[3], "w")) == 0) {
    	fprintf(stderr, "File creation unsuccesful\n");
    } else {
    	//fprintf(stderr, "File creation succesful!\n");
    }

    //Print integers to file
    for (i = lower; i <= upper; i++) {
        fprintf(output, "%d\n", i);
    }

    //Close output file
    fclose(output);

    return EXIT_SUCCESS;
}