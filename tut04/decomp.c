// Author: Danilo Scodellaro
// Date created: 06-JUN-2014
// cs1911 tut04
// log10.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    char integer[6] = {};
    int i = 0;

    printf("Please enter an integer: \n");
    scanf("%s", integer);
    printf("You entered %s\nWhich is decomposed: ", integer);

    for (i = 0; i < strlen(integer); i++) {
        printf("%c ", integer[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}