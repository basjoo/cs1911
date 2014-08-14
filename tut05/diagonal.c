// Author: Danilo Scodellaro
// Date created: 07-JUN-2014
// cs1911 tut05
// diagonal.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    int integer = 0;
    int i = 0;
    int j = 0;

    printf("Please enter an integer: ");
    scanf("%d", &integer);

    for (i = 0; i < integer; i++) {
        for (j = i; j > 0; j--) {
            printf(" ");
        }
        printf("*\n");
    }

    return EXIT_SUCCESS;
}