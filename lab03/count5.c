// Author: Danilo Scodellaro
// Date created: 26-Mar-2014
// Requests an integer from the user, returning the number word for 
// values 1-5 and another statement otherwise
// cs1911 lab04

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, const char *argv[]) {
	int x = 0;
	//Initialise the variable

	printf("Please enter an integer:\n");
	scanf("%d", &x);
	printf("You entered:\n");
	//Take user input and assign to variable

	if (x == 1) {
		printf("one\n");
	} else if (x == 2) {
		printf("two\n");
	} else if (x == 3) {
		printf("three\n");
	} else if (x == 4) {
		printf("four\n");
	} else if (x == 5) {
		printf("five\n");
	} else if (x < 1) {
		printf("a number less than one\n");
	} else {
		printf("a number greater than five\n");
	}
	//Print result to user

	return EXIT_SUCCESS;
}