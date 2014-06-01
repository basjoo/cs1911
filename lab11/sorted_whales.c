// Author: Danilo Scodellaro
// z3414551
// Date created: 25-MAY-2014
// cs1911
// Lab 11 - sorted_whales.c

// INPUT
// sortmode is provided by command line argument
// Each line contains first the number of whales in the pod followed by the 
// species of whales
// e.g. 15 humpbacks
// Each line with be no longer than 256 characters
// No more than 128 different whale species will be entered
// No whale name is longer than 128 characters

// DESCRIPTION
// Program which prints a tally of how many of each whale species were seen
// -s as command line argument prints whale tallies in decreasing frequency

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_SPECIES 128
#define MAX_NAME_LENGTH 128
#define SORT_FLAG "-s"

int main(int argc, char const *argv[]) {
	
	//Declare Variables
	char whaleTemp[MAX_NAME_LENGTH] = {};
	int countTemp = 0;
	int exitCondition = 0;
	char c;
	int i = 0;
	int j = 0;
	int sortTempCount = 0;
	char sortTempName[MAX_NAME_LENGTH];
	char whaleNameArray[MAX_SPECIES][MAX_NAME_LENGTH] = {};
	int whaleCountArray[MAX_SPECIES];
	int matchFlag = 0;
	char whaleNameArrayS[MAX_SPECIES][MAX_NAME_LENGTH] = {};
	int whaleCountArrayS[MAX_SPECIES];
	int swapTrue = 1;

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

	//Duplicate Array
	for (i = 0; i < j; i++) {
		whaleCountArrayS[i] = whaleCountArray[i];
		strcpy(whaleNameArrayS[i], whaleNameArray[i]);
	}

	//Bubblesort
while (swapTrue == 1) {
	swapTrue = 0;
	for (i = 1; i < j; i++) {

		if (whaleCountArrayS[i] > whaleCountArrayS[i-1]) {
			//Numbers
			sortTempCount = whaleCountArrayS[i-1];
			whaleCountArrayS[i-1] = whaleCountArrayS[i];
			whaleCountArrayS[i] = sortTempCount;
			//Char Strings
			strcpy(sortTempName, whaleNameArrayS[i-1]);
			strcpy(whaleNameArrayS[i-1], whaleNameArrayS[i]);
			strcpy(whaleNameArrayS[i], sortTempName);
			swapTrue = 1;
		} else if (whaleCountArrayS[i] == whaleCountArrayS[i-1]) {
			//Alphabetize
			if (strcmp(whaleNameArrayS[i], whaleNameArrayS[i-1]) < 0) {
				//Numbers
				sortTempCount = whaleCountArrayS[i-1];
				whaleCountArrayS[i-1] = whaleCountArrayS[i];
				whaleCountArrayS[i] = sortTempCount;
				//Char Strings
				strcpy(sortTempName, whaleNameArrayS[i-1]);
				strcpy(whaleNameArrayS[i-1], whaleNameArrayS[i]);
				strcpy(whaleNameArrayS[i], sortTempName);
				swapTrue = 1;
			}
		}
	}
}
	//Print Results
	if (argc > 1 && strcmp(argv[1], SORT_FLAG) == 0) {
		for (i = 0; i < j; i++) {
			printf("%d %s\n", whaleCountArrayS[i], whaleNameArrayS[i]);
		}
	} else {	
		for (i = 0; i < j; i++) {
			printf("%d %s\n", whaleCountArray[i], whaleNameArray[i]);
		}
	}

	return EXIT_SUCCESS;
}