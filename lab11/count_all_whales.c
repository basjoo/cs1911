// Author: Danilo Scodellaro
// z3414551
// Date created: 25-MAY-2014
// cs1911
// Lab 11 - count_all_whales.c

// INPUT
// Each line contains first the number of whales in the pod followed by the 
// species of whales
// e.g. 15 humpbacks
// Each line with be no longer than 256 characters
// No more than 128 different whale species will be entered
// No whale name is longer than 128 characters

// DESCRIPTION
// Program which prints a tally of how many of each whale species were seen

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_SPECIES 128
#define MAX_NAME_LENGTH 128

int main(int argc, char const *argv[]) {
	
	//Declare Variables
	char whaleTemp[MAX_NAME_LENGTH];
	int countTemp = 0;
	int exitCondition = 0;
	char c;
	int i = 0;
	int j = 0;
	char whaleNameArray[MAX_SPECIES][MAX_NAME_LENGTH] = {};
	int whaleCountArray[MAX_SPECIES];
	int matchFlag = 0;

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
				ungetc(c, stdin);
			}
		} while (c != ' ');		

		//Get name of whale
		char whaleTemp[MAX_NAME_LENGTH] = {'\0'};
		for (i = 0; i < MAX_NAME_LENGTH; i++) {
			c = getc(stdin);
			if (c != '\0' && c != '\n') {
				whaleTemp[i] = c;
			} else {
				whaleTemp[i] = '\0';
				break;
			}
		}

		//Loop check to determine if whale already encountered 
		for (i = 0; i < MAX_SPECIES; i++) {
			if (strcmp(whaleTemp, whaleNameArray[i]) == 0) {
				whaleCountArray[i] = whaleCountArray[i] + countTemp;
				matchFlag = 1;
				break;
			}
		}

		//If not already encountered
		if (matchFlag == 0) {
			strcpy(whaleNameArray[j], whaleTemp);
			whaleCountArray[j] = countTemp;
			j = j + 1;
		}

		//Reset Flag
		matchFlag = 0;
	}

	//Print Results
	for (i = 0; i < j; i++) {
		printf("%d %s\n", whaleCountArray[i], whaleNameArray[i]);
	}

	return EXIT_SUCCESS;
}