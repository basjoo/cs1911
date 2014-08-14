// Author: Danilo Scodellaro
// Date created: 08-JUN-2014
// cs1911 tut07
// line_length.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096

int main(int argc, char const *argv[]) {

    char c[4096] = {};
    int i = 0;

    while (i < MAX_LINE_LENGTH) {
        if (fgets(c, 2, stdin) == NULL) {
            break;
        }
        i++;
    }

    printf("line %d characters long\n", i - 1);

    return EXIT_SUCCESS;
}