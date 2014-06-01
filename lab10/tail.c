// Author: Danilo Scodellaro
// z3414551
// Date created: 14-MAY-2014
// cs1911
// Lab 10 - tail.c

// DESCRIPTION
// program which given a single argument n prints the last 10 
// lines of the file. If the file has less than 10 lines the 
// entire file should be printed.

// ARGUMENTS
// You should print a suitable message if incorrect arguments are 
// supplied or the file can not be read.
// Unlike the previous exercise it does not have to be possible 
// to specify a different number of lines to be printed

// BUT THIS CODE CAN!!!!!!!!!!!!!!!!!!!!!!!
// via #define change, but it would be fairly trivial to request user
// input or take from command line arguments

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define LINES_DEFAULT 10

int main(int argc, char const *argv[]) {

	//Initialise Variables
	int i = 0;
	int lines = LINES_DEFAULT;
	FILE *input;
	int inputLines = 0;
	char test = 0;

	//Open file
	if ((input = fopen(argv[1], "r")) == 0) {
    	fprintf(stderr, "File access unsuccesful\n");
	} else if (argc != 2) {
    	fprintf(stderr, "Incompatible arguments\n"
    					"Please specify input file\n");
	}
	
	//Initialise array
	char output [MAX_LINE_LENGTH] = "";

	//Determine how many lines in input file
	while (test != EOF) { 
		test = fgetc(input);
		if (test == '\n') {
			++inputLines;
		} 
	}

	//Rewind to start, then incremenent to ten lines before finish
	rewind (input);
	for (i = 0; i < (inputLines - lines); ) {
		test = fgetc(input);
		if (test == '\n') {
			++i;
		}
	}

	//Transfer lines from file to array, and print
    for (i = 0; i < lines; i++) {
    	if (fgets(output, MAX_LINE_LENGTH, input) == 0) {
    		i = lines;
    	}
    	if (i != lines) {
    		fputs(output, stdout);
    	}
    }
    fclose(input);

    return EXIT_SUCCESS;
}
