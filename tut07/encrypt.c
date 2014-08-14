// Author: Danilo Scodellaro
// Date created: 17-JUN-2014
// cs1911 tut07
// encrypt.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    char c = 0;

    while (c != EOF){
        c = getchar();
        if (c == EOF) {
            break;
        } else if (c == 'z') {
            putchar('a');
        } else if (c == 'Z') {
            putchar('A');
        } else if (c >= 'a' && c <= 'z') {
            putchar(c + 1);
        } else if (c >= 'A' && c <= 'Z') {
            putchar(c + 1);
        } else {
            putchar(c);
        }
    }

    return EXIT_SUCCESS;
}