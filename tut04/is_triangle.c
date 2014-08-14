// Author: Danilo Scodellaro
// Date created: 05-JUN-2014
// cs1911 tut04
// is_triangle.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

    int i = 0;
    int sides[3] = {};
    int triangle = 1;
    
    printf("Please enter three integers: ");
    for (i = 0; i < 3; i++) {
        scanf("%d", &sides[i]);
    }

    if (sides[0] + sides[1] < sides[2]) {
        triangle = 0;
    } else if (sides[1] + sides[2] < sides[0]) {
        triangle = 0;
    } else if (sides [2] + sides[0] < sides[1]) {
        triangle = 0;
    }

    if (triangle == 1) {
        printf("Numbers are the sides of a triangle\n");
    } else {
        printf("Numbers are not the sides of a triangle\n");
    }

    return EXIT_SUCCESS;
}