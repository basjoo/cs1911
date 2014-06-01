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

    printf("Your sorted integers in non-ascending order are:\n");

    if (x>=y && y>=z) {
        printf("%d %d %d\n", x, y, z);
    } else if (y>=z && z>=x) {
        printf("%d %d %d\n", y, z, x);
    } else if (z>=x && x>=y) {
        printf("%d %d %d\n", z, x, y);
    } else if (z>=y && y>=x) {
        printf("%d %d %d\n", z, y, x);
    } else if (y>=x && x>=z) {
        printf("%d %d %d\n", y, x, z);
    } else if (x>=z && z>=y) {
        printf("%d %d %d\n", x, z, y);
    }

    return EXIT_SUCCESS;
}

