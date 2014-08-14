// Author: Danilo Scodellaro
// Date created: 06-JUN-2014
// cs1911 tut04
// multiple_of_ten.c

#include <stdio.h>
#include <stdlib.h>

#define MULTIPLE 10

int main(int argc, char const *argv[]) {

    int start = 0;
    int finish = 0;

    printf("Enter start: ");
    scanf("%d", &start);
    printf("Enter finish: ");
    scanf("%d", &finish);

    for(start = start; start < finish; start++) {
        if (start % MULTIPLE == 0) {
            printf("%d\n", start);
        }
    }

    return EXIT_SUCCESS;
}