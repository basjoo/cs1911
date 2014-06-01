// Author: Danilo Scodellaro
// Date created: 26-Mar-2014
// Convert height from centimeters to inches. 
// (assuming 1in = 2.54cm) - 'rounded up or down to full inches.
// cs1911 lab04

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define RATIO 2.54
//RATIO refers to ration of centimetres to inches: 2.54 cm per inch
#define FOOT 12
//FOOT is the number of inches in one imperial foot

int main (int argc, char *argv[]) {
    double heightCm = 0;
    int    heightIn = 0;
    int    feet = 0;
    int    inch = 0;

    printf("Enter your height in centimeters: ");

    scanf("%lf", &heightCm);
  
    heightIn = (int)(heightCm / RATIO);
    feet = (heightIn / FOOT);
    inch = (heightIn % FOOT);

    printf("Your height in feet and inches is: "
           "%d feet %d inches\n", feet, inch);

    return EXIT_SUCCESS;
}

