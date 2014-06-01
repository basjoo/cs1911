// Author: Danilo Scodellaro
// Date created: 01-APR-2014
// cs1911 lab05
// DESCRIPTION
// This program prints the sum of the integers from 1 to k, 
// for all values of k between 1 and 20

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, const char *argv[]) {
    int sum = 0;
    printf("k  sum\n\n");
    for (int k=1; k<=20; k++){
        sum = sum + k;
        printf("%2d  %3d\n", k, sum);
    }
return EXIT_SUCCESS;
}