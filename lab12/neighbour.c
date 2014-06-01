// Author: Danilo Scodellaro
// z3414551
// Date created: 31-MAY-2014
// cs1911
// Lab 12 - neighbour.c

// INPUT
// Text file containing the Latitude, Longitude and Name of Australian Towns
// Town name given as command line argument

// DESCRIPTION
// Program which reads the file atlas.txt and takes in latitude and longitude
// Prints the Australian town closest to that point

// ASSUMPTIONS
// No place name longer than 32 characters
// File contains a maximum of 10000 lines
// Distance between two points (latitude1, longitude1) and 
// (latitude2, longitude2) is: sqrt((latitude1-latitude2)*(latitude1-latitude2)
// +(longitude1-longitude2)*(longitude1-longitude2))

// RESTRICTIONS
// The distance calculation must be a seperate function

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LENGTH 32
#define MAX_FILE_LINES 10000
#define MAX_LAT_LONG_LENGTH 20

int distanceCalc(double lat1, double long1, double *lat2, double *long2);

int main(int argc, char const *argv[]) {

	//Initialise Variables
	FILE *atlas;
	char c = '0';
	char townNames[MAX_FILE_LINES][MAX_NAME_LENGTH] = {"\0"}; 
	double lat2[MAX_FILE_LINES] = {};
	double long2[MAX_FILE_LINES] = {};
	double lat1 = 0;
	double long1 = 0;
	char lat2Temp[MAX_LAT_LONG_LENGTH] = {};
	char long2Temp[MAX_LAT_LONG_LENGTH] = {};
	int i = 0;
	int j = 0;
	int matchFlag = 0;
	int n = 0;

	//Validate Arguments
	if (argc != 2) {
		fprintf(stderr, "Insufficient arguments\n");
		return EXIT_FAILURE;
	}

	//Open file
	if ((atlas = fopen("atlas.txt", "r")) == 0) {
    	fprintf(stderr, "File access unsuccesful\n");
    	return EXIT_FAILURE;
	}

	//Read Latitude, Longitude, Name
	while (feof(atlas) == 0) {	
		fscanf(atlas, "%s", lat2Temp);
		lat2[i] = atof(lat2Temp);
		fscanf(atlas, "%s", long2Temp);
		long2[i] = atof(long2Temp);
		c = fgetc(atlas);
		for (j = 0; j < MAX_NAME_LENGTH; j++) {
			c = fgetc(atlas);
			if (c != '\0' && c != '\n') {
				townNames[i][j] = c;
			} else {
				townNames[i][j] = '\0';
				break;
			}
		}
		i = i + 1;
	}
	clearerr(atlas);

	//Close File
	fclose(atlas);

	//Convert arguments into Co-ordinates
	for (i = 0; i < MAX_FILE_LINES; i++) {
		if (strcmp(argv[1], townNames[i]) == 0) {
			matchFlag = 1;
			n = i;
			break;
		}
	}
	if (matchFlag == 0) {
		fprintf(stderr, "Town %s not in atlas\n", argv[1]);
	} else {
		lat1 = lat2[n];
		long1 = long2[n];
	}

	//Determine distance index
	i = distanceCalc(lat1, long1, lat2, long2);

	//Print Results
	printf("The closest town to %s is %s\n", argv[1], townNames[i]);

	return EXIT_SUCCESS;
}

int distanceCalc(double lat1, double long1, double *lat2, double *long2) {

	//Initialise Variables
	double distTemp = 0;
	double distKeep = 0;
	int i = 0;		//Running index
	int n = 0;		//Index of closest town
	//char c = '0';

	//Determine shortest distance between points, record town index
	while (i < MAX_FILE_LINES) {
		if (lat2[i] == lat1 && long2[i] == long1) {
			i = i + 1;
			continue;
		}
		distTemp = sqrt(pow((lat1-lat2[i]), 2) + pow((long1-long2[i]), 2));
		if (i == 0) {
			distKeep = distTemp;
		} else if (distTemp < distKeep) {
			distKeep = distTemp;
			n = i;
		} 
		i = i + 1;
	}

	//Return index to main
	return n;
}