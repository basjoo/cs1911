// Author: Danilo Scodellaro
// z3414551
// Date created: 11-MAY-2014
// cs1911
// Lab 09 - tac.c

// DESCRIPTION
// Program reads lines of input and until the end-of-input 
// and then prints them in reverse order.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_LINE_LENGTH 128
#define MAX_LINES 1024

int main(int argc, char *argv[]) {

	//Declare Variables
	int i = 1;
	char raw[MAX_LINES][MAX_LINE_LENGTH] = {{"\0"},{"\0"}};
    
    // Store user input
	for (i = 1; i < MAX_LINES; ++i)	{
		if (fgets(raw[i], MAX_LINE_LENGTH, stdin) == NULL) {
			break;
		}
	}

    //Print string line by line
    for (i = i; i > 0; --i) {
    	fputs(raw[i], stdout);
    }

	return EXIT_SUCCESS;
}