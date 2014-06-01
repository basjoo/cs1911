// Author: Danilo Scodellaro
// Date created: 26-Mar-2014
// Sort 3 numbers from high to low 
// cs1911 lab04

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char *argv[]) {
    int x = 0;
    int y = 0;
    int z = 0;
    //The above 3 variables are the unsorted inputs

    printf("Please enter three integers: ");

    scanf("%d %d %d", &x, &y, &z);

    int a = z;
    int b = z;
    int c = z;
    //The above 3 variables are the sorted inputs

    if (x>y && x>z) {
        a = x;
        } else if (y>x && y>z) {
            a = y;
        }
    
    if (x<y && x<z) {
        c = x;
        } else if (y<x && y<z) {
            c = y;
        } 

    if (x!=a && x!=c) {
        b = x;
        } else if (y!=a && y!=c) {
            b = y;
        }
    
    printf("Your sorted integers in non-ascending order are:\n" 
           "%d %d %d\n", a, b, c);

    return EXIT_SUCCESS;
}

