// Author: Danilo Scodellaro
// Date created: 08-JUN-2014
// cs1911 tut07
// sum_digits.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    char c = 0;
    int i = 0;
    int sum = 0;

    while (c != EOF) {
        c = getchar();
        if (c > '0' && c < '9') {
            sum = sum + c - '0';
            i++;
        }
    }

    printf("%d digits which summed to %d\n", i, sum);

    return EXIT_SUCCESS;
}