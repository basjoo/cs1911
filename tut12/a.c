// Author: Danilo Scodellaro
// Date created: 17-JUN-2014
// cs1911 tut12
// a.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096

int main(int argc, char const *argv[]) {

    FILE *fines;
    char firstName[10][100] = {{'\0'}};
    char lastName[10][100] = {{'\0'}};
    int fee[10] = {0};
    char reason[10][100] = {{'\0'}};
    char c = 0;
    int largest = 0;
    int r = 0;
    int i = 0;
    char waste[100] = {'\0'};

    //printf("opening file\n");
    if ((fines = fopen("fines.txt", "r")) == NULL) {
        perror("Unable to open file");
    }

    //printf("file opened\n");
    while (feof(fines) == 0) {
        fscanf(fines, "%s %s", firstName[i], lastName[i]);
        //printf("names scanned\n");
        c = fgetc(fines);
        while (c != '$') {
            c = fgetc(fines);
        }
        //printf("$ scanned\n");
        fscanf(fines, "%d", &fee[i]);
        //printf("fee scanned\n");
        if (fee[i] > largest) {
            largest = fee[i];
            r = i;
        }
        //printf("Largest determined\n");
        fscanf(fines, "%s", waste);
        fgetc(fines);
        fgets(reason[i], 99, fines);
        //printf("reason scanned\n");

        i = i + 1;
        //printf("i + 1\n");
    }

    fclose(fines);

    printf("Biggest fine was $%d given to %s %s for '%s'\n", fee[r], firstName[r], lastName[r], reason[r]);

    return EXIT_SUCCESS;
}