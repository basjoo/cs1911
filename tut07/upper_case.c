// Author: Danilo Scodellaro
// Date created: 08-JUN-2014
// cs1911 tut07
// upper_case.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    char c = 0;

    while (c != EOF){
        c = getchar();
        if (c == EOF) {
            break;
        } else if (c >= 97 && c <= 122) {
            putchar(c-32);
        } else {
            putchar(c);
        }
    }

    return EXIT_SUCCESS;
}