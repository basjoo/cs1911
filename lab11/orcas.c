// Author: Danilo Scodellaro
// z3414551
// Date created: 25-MAY-2014
// cs1911
// Lab 11 - orcas.c

// INPUT
// Each line contains first the number of whales in the pod followed by the 
// species of whales
// e.g. 15 humpbacks
// Each line with be no longer than 256 characters
// No more than 128 different whale species will be entered
// No whale name is longer than 128 characters

// DESCRIPTION
// Program which prints the number of orcas pods and the total number of orcas
// within those pods

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_SPECIES 128
#define MAX_NAME_LENGTH 128

int main(int argc, char const *argv[]) {
	
	//Declare Variables
	int whalePods = 0;
	int whaleCount = 0;
	char whaleTemp[MAX_NAME_LENGTH];
	int countTemp = 0;
	int exitCondition = 0;
	char c;
	char whaleType[MAX_NAME_LENGTH];
	int i = 0;

	//Set whaleType to orcas
	strcpy (whaleType, "orcas"); 
	
	//Read input
	while (exitCondition == 0) {
		//Get no. of whales in line
		if (scanf("%d", &countTemp) != 1) {
			exitCondition = 1;
			break;
		}
		//Ignore whitespace
		do {
			c = getc(stdin);
			if (c != ' ') {
				ungetc (c, stdin);
			}
		} while (c != ' ');		
		//Get name of whale
		for (i = 0; i < MAX_NAME_LENGTH; i++) {
			c = getc(stdin);
			if (c != '\0' && c != '\n') {
				whaleTemp[i] = c;
			} else {
				whaleTemp[i] = '\0';
				break;
			}
		}
		//Check if desired whale
		if (strcmp(whaleTemp, whaleType) == 0) {
			whalePods = whalePods + 1;
			whaleCount = whaleCount + countTemp;
		}
	}

	//Print Results
	printf("%s count: %d pods containing %d whales\n", whaleType, whalePods, 
		whaleCount);

	return EXIT_SUCCESS;
}