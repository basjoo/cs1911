// Author: Danilo Scodellaro
// Date created: 01-APR-2014
// cs1911 lab05
// DESCRIPTION
// Program reads an integer n from standard input and prints the 
// decomposition of n into prime factors. If n is prime it instead 
// should print a message indicating this

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, const char *argv[]) {
    long n = 0;      //input number
    long sum = 0;    //sum of factors
    long i = 0;      //counter # 1
    long k = 0;      //counter # 2
    long n2 = 0;     //duplicate of the initial input
    long factor = 2;

    printf("Enter number: ");
    scanf("%ld", &n);
    n2 = n;          //make n2 = n, n2 will remain constant

    //Test if prime
    for ( i = 1; i <= n2; i++) {
        if (n2 % i == 0) {
            //no printout this run.
            sum = sum + i;
        }
    }    
    if (sum == n2 + 1 || n2 == 1) {
        printf("%ld is prime\n", n2);

    //If the number is not prime, it will be decomposed
    } else {        
        printf("The prime factorization of %ld is:\n", n2);
        for ( k = 1; k < n2; k++) {
            if (n % factor == 0) {
                if (n != n2) {      //Will not print "* " first time
                    printf("* ");
                }
                printf("%ld ", factor);
                n = n / factor;
            } else {
                factor = factor + 1;//Increment factor by 1, try again
            }
        }
        printf("= %ld\n", n2);      //Product of factors = input
    }
    return EXIT_SUCCESS;
}