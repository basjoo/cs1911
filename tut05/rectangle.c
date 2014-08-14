// Author: Danilo Scodellaro
// Date created: 07-JUN-2014
// cs1911 tut05
// rectangle.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    int i = 0;
    int j = 0;
    int height = 0;
    int length = 0;

    printf("Enter rectangle height and length: ");
    scanf("%d %d", &height, &length);
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < length; j++) {
            if (i == 0 || i == height - 1) {
                printf("* ");
            } else if (j == 0 || j == length - 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");        
    }

    return EXIT_SUCCESS;
}