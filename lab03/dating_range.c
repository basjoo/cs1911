// Author: Danilo Scodellaro
// Date created: 26-Mar-2014
// cs1911 lab03
// This program takes a person's age, and returns their 'dating range'

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, const char *argv[]) {
	int age = 0;
	//Initialise the variable

	printf("Enter your age: ");
	scanf("%d", &age);

	int low = (age/2+7);
	int high = (age+2*(age-low));

	if (high-low<=0) {
	// If there is no or negative dating range, the user is too young
		printf("You are too young to be dating.\n");
	} else {
		printf("Your dating range is %d to %d years old.\n", low, high);
	}
	return EXIT_SUCCESS;
}