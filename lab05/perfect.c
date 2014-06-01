// Author: Danilo Scodellaro
// Date created: 01-APR-2014
// cs1911 lab05
// DESCRIPTION
// This program reads a positive integer n from standard input and 
// prints all the factors of n, their sum and if indicates if n is a 
// perfect number

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, const char *argv[]) {
    int n = 0;      //input number
    int sum = 0;    //sum of factors
    int i = 0;      //counter

    printf("Enter number: ");
    scanf("%d", &n);
    printf("The factors of %d are:\n", n);

    //loop for factors
    for ( i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d\n", i);
            sum = sum + i;
        }
    }

    printf("Sum of factors = %d\n", sum);
    if (sum == 2*n) {
        printf("%d is a perfect number\n", n);
        } else {
            printf("%d is not a perfect number\n", n);
        }
    
return EXIT_SUCCESS;
}