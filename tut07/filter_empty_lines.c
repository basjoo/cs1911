// Author: Danilo Scodellaro
// Date created: 17-JUN-2014
// cs1911 tut07
// filter_empty_lines.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096

int main(int argc, char const *argv[]) {

    char line[MAX_LINE_LENGTH] = {};
    int i = 0;
    int flag = 0;

while (line[0] != EOF) {

    for (i = 0; i < MAX_LINE_LENGTH; i++) {
        line[i] = '\0';
    }

    flag = 0;
    fgets(line, MAX_LINE_LENGTH - 1, stdin);

    for (i = 0; i < MAX_LINE_LENGTH; i++) {
        if (line[i] == ' ' || line[i] == '\n' || line[i] == 9) {
            flag = 0;
        } else {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        continue;
    } else {
        for (i = 0; i < MAX_LINE_LENGTH; i++) {
            printf("%c", line[i]);
        }
    }
}



    return EXIT_SUCCESS;
}