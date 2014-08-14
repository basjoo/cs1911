// Author: Danilo Scodellaro
// Date created: 07-JUN-2014
// cs1911 tut06
// dot_product.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

int main(int argc, char const *argv[]) {

    int vector1[SIZE] = {};
    int vector2[SIZE] = {};
    int dotProduct = 0;
    int i = 0;

    printf("Enter vector 1 of %d numbers: ", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &vector1[i]);
    }

    printf("Enter vector 2 of %d numbers: ", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &vector2[i]);
    }

    for (i = 0; i < SIZE; i++) {
        dotProduct = dotProduct + vector1[i]*vector2[i];
    }

    printf("Their dot-product is %d\n", dotProduct);

    return EXIT_SUCCESS;
}