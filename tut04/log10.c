// Author: Danilo Scodellaro
// Date created: 06-JUN-2014
// cs1911 tut04
// log10.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    char integer[6] = {};
    int output = 0;

    printf("Enter a positive integer: ");
    scanf("%s", integer);

    output = strlen(integer) - 1;

    printf("log10 of %s is %d\n", integer, output);

    return EXIT_SUCCESS;
}