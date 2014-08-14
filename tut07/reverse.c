// Author: Danilo Scodellaro
// Date created: 17-JUN-2014
// cs1911 tut07
// reverse.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096

int main(int argc, char const *argv[]) {

    char line[MAX_LINE_LENGTH] = {};
    int i = 0;

    fgets (line, MAX_LINE_LENGTH - 1, stdin);

    for (i = strlen(line); i >= 0; i--) {
        printf("%c", line[i]);
    }


    return EXIT_SUCCESS;
}