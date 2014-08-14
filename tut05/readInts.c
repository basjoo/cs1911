// Author: Danilo Scodellaro
// Date created: 07-JUN-2014
// cs1911 tut05
// readInts.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main(int argc, char const *argv[]) {

    int integer[SIZE] = {};
    int i = 0;

    printf("Please enter some integers: \n");
    

    while (scanf("%d", &integer[i]) != 0) {
        i++;
    }

    /*
    for (i = 0; i < SIZE; i++) {
        printf("%d", scanf("%d", &integer[i]));
    }
    printf("\n i = %d\n", i);

    for (i = 0; i < SIZE; i++) {
        printf("%d ;", integer[i]);
    }

    */
    
    printf("You entered %d integers\n", i);

    return EXIT_SUCCESS;
}