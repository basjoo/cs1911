// Author: Danilo Scodellaro
// Date created: 07-JUN-2014
// cs1911 tut05
// diamond.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main(int argc, char const *argv[]) {

    int i = 0;
    int j = 0;
    int length = 0;

    printf("Enter side length: ");
    scanf("%d", &length);

    int height = length;
    
    //UP Triangle
    for (i = 0; i < height; i++) {
        for (j = 0; j < length*2; j++) {
            if (j == length - 1 - i || j == length - 1 + i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");        
    }

    //DOWN Triangle
    for (i = i - 2; i > -1; i--) {
        for (j = 0; j < length*2; j++) {
            if (j == length - 1 - i || j == length - 1 + i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");        
    }

    return EXIT_SUCCESS;
}