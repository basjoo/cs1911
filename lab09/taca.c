// Author: Danilo Scodellaro
// z3414551
// Date created: 11-MAY-2014
// cs1911
// Lab 09 - taca.c

// DESCRIPTION
// Program takes a series of command-line arguments and prints
// them out in reverse order one per line

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[]) {

	//Declare Variables
	int i = 0;

	//Loop to print each cmd line argument, in reverse order
	for (i = argc - 1; i > 0; i--) {
		printf("%s\n", argv[i]);
	}

	return EXIT_SUCCESS;
}

