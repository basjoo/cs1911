// Author: Danilo Scodellaro
// Date created: 17-JUN-2014
// cs1911 tut07
// strip_comments.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096

int main(int argc, char const *argv[]) {

    char line[MAX_LINE_LENGTH] = {};
    int i = 0;

    fgets(line, MAX_LINE_LENGTH - 1, stdin);

    for (i = 0; i < MAX_LINE_LENGTH; i++) {
        if (line[i] == '/' && line[i+1] == '/') {
            break;
        } else {
            printf("%c", line[i]);
        }
    }



    return EXIT_SUCCESS;
}