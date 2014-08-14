// Author: Danilo Scodellaro
// Date created: 17-JUN-2014
// cs1911 tut07
// input_statistics.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096

int main(int argc, char const *argv[]) {

    char line[MAX_LINE_LENGTH] = {'\0'};
    int i = 0;
    int blanks = 0;
    int words = 0;
    int shortest = MAX_LINE_LENGTH;
    int longest = 0;
    int temp = 0;

    for (i = 0; i < MAX_LINE_LENGTH - 1; i++) {
        line[i] = getchar();
        if (line[i] == EOF) {
            line[i] = '\0';
            break;
        }
    }

    for (i = 0; i <= strlen(line); i++) {
        if (line[i] == ' ' || line[i] == '\n' || line[i] == 9) {
            blanks = blanks + 1;
            if (temp < shortest && temp > 1) {
                shortest = temp;
            }
            if (temp > 0) {
                words = words + 1;
            }
            temp = 0;
        } else {
            temp = temp + 1;
        }
        if (temp > longest) {
            longest = temp;
        }
    }

    printf("Input contains %d blanks, tabs and new lines\n", blanks);
    printf("Number of words: %d\n", words);
    printf("Length of shortest word: %d\n", shortest);
    printf("Length of longest word: %d\n", longest);

    return EXIT_SUCCESS;
}