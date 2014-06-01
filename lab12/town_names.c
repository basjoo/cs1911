// Author: Danilo Scodellaro
// z3414551
// Date created: 30-MAY-2014
// cs1911
// Lab 12 - town_names.c

// INPUT
// Text file containing the Latitude, Longitude and Name of Australian Towns

// DESCRIPTION
// Program which reads the file atlas.txt and prints just the town names,
// one name per line

// ASSUMPTIONS
// No place name longer than 32 characters

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LENGTH 32

int main(int argc, char const *argv[]) {

	//Initialise Variables
	FILE *atlas;
	char c = '0';
	char townName[MAX_NAME_LENGTH] = {}; 

	//Open file
	if ((atlas = fopen("atlas.txt", "r")) == 0) {
    	fprintf(stderr, "File access unsuccesful\n");
	}

	//Loop through entire program for each line
	while (fgetc(atlas) != EOF) {	

		//Skip over Latitude and Longitude
		do {
			c = fgetc(atlas);
		} while (c < 'A' || c > 'z');
		ungetc(c, atlas);

		//Get and print town name
		if (fgets(townName, MAX_NAME_LENGTH, atlas) != NULL) {
			fputs(townName, stdout);
		}
	}

	//Close File
	fclose(atlas);

	return EXIT_SUCCESS;
}