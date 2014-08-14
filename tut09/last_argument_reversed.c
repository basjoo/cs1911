// Author: Danilo Scodellaro
// Date created: 17-JUN-2014
// cs1911 tut09
// last_argument_reversed.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096

int main(int argc, char const *argv[]) {

    char line[MAX_LINE_LENGTH] = {};
    int i = 0;

    if (argc <= 1 ) {
        return EXIT_FAILURE;
    } else {
        strcpy(line, argv[argc-1]);
    }

    for (i = strlen(line); i >= 0; i--) {
        putc(line[i], stdout);
    }
    printf("\n");

    return EXIT_SUCCESS;
}