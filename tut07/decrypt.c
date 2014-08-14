// Author: Danilo Scodellaro
// Date created: 17-JUN-2014
// cs1911 tut07
// decrypt.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    char c = 0;

    while (c != EOF){
        c = getchar();
        if (c == EOF) {
            break;
        } else if (c == 'a') {
            putchar('z');
        } else if (c == 'A') {
            putchar('Z');
        } else if (c >= 'a' && c <= 'z') {
            putchar(c - 1);
        } else if (c >= 'A' && c <= 'Z') {
            putchar(c - 1);
        } else {
            putchar(c);
        }
    }

    return EXIT_SUCCESS;
}