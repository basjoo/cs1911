// Author: Danilo Scodellaro
// z3414551
// Date created: 13-MAY-2014
// cs1911
// Lab 10 - head.c

// DESCRIPTION
// program which given a single argument n prints the first 10 
// lines of the file. If the file has less than 10 lines the 
// entire file should be printed.

// ARGUMENTS
// It should also be possible to specify that a different number 
// of lines be printed.This will specified by passing the string 
// "-n" as the first argument to the program, the number of lines
// to be printed as the second argument and the file as the third 
// argument.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define LINES_DEFAULT 10
#define FLAG_VALUE "-n"

int main(int argc, char const *argv[]) {

	//Initialise Variables
	int i = 0;
	int lines = LINES_DEFAULT;
	FILE *input;
	char *flag = FLAG_VALUE;

	//Determine how to handle arguments
	//And open files
	if (strcmp(argv[1], flag) != 0) {
    	//fprintf(stderr, "Opening %s ...\n", argv[1]);
		if ((input = fopen(argv[1], "r")) == 0) {
    		fprintf(stderr, "File access unsuccesful\n");
    	} else {
    		//fprintf(stderr, "File access succesful!\n");
    	}
	} else if (strcmp(argv[1], flag) == 0) {
		lines = atoi(argv[2]);
    	//fprintf(stderr, "Opening %s ...\n", argv[3]);
		if ((input = fopen(argv[3], "r")) == 0) {
    		fprintf(stderr, "File access unsuccesful\n");
    	} else {
    		//fprintf(stderr, "File access succesful!\n");
		}
	} else {
    	fprintf(stderr, "Unsuitable arguments\n"
    					"Please enter 1 or 3 arguments\n");
	}
	
	//Initialise array
	char output [MAX_LINE_LENGTH] = "";

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
