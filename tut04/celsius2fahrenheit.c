// Author: Danilo Scodellaro
// Date created: 05-JUN-2014
// cs1911 tut04
// celcius2fahrenheit.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    
    double fTemp = 0;
    double cTemp = 0;

    printf("Enter Fahrenheit temperature: ");
    scanf("%lf", &fTemp);

    cTemp = (5*(fTemp - 32))/9; 

    printf("%lf Fahrenheit = %lf Celsius\n", fTemp, cTemp);

    return EXIT_SUCCESS;
}