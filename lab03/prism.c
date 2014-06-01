// Author: Danilo Scodellaro
// Date created: 26-Mar-2014
// Given the dimensions of a rectangular prism, this progam calculates
// the volume, area and edge length
// cs1911 lab03

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char const *argv[]) {
    int x = 0;
    int y = 0;
    int z = 0;
    //Initialise Variables

    printf("Please enter length of three sides :\n");
    scanf("%d %d %d", &x, &y, &z);
    //Take all side lengths and store as variables x y z

    int volume = (x*y*z);
    int area = 2*(x*y+x*z+y*z);
    int edge = 4*(x+y+z);
    //Calculate volume, area and edge length

    printf("For a prism with sides %d %d %d, we obtain\n\n", x,y,z);
    printf("Volume      = %d\n", volume);
    printf("Area        = %d\n", area);
    printf("Edge length = %d\n", edge);
    //Display results to user

    return EXIT_SUCCESS;
}