// Author: Danilo Scodellaro
// Date created: 07-JUN-2014
// cs1911 tut06
// a.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

int main(int argc, char const *argv[]) {

    int integer[SIZE] = {};
    int target = 0;
    int i = 0;
    int occur = 0;

    printf("Enter %d numbers: ", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &integer[i]);
    }

    printf("Enter a number: ");
    scanf("%d", &target);

    for (i = 0; i < SIZE; i++) {
        if (integer[i] == target) {
            occur = occur + 1;
        }
    }

    printf("%d occurred %d times in the %d numbers read\n", target, occur, SIZE);

    return EXIT_SUCCESS;
}