// Author: Danilo Scodellaro
// Date created: 26-Mar-2014
// Given two years, printout all leapyears that fall between the two
// cs1911 lab04

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char *argv[]) {
   int start = 0;
   int finish = 0;
    

   printf("Enter start year: ");
   scanf("%d", &start);
   printf("Enter finish year: ");
   scanf("%d", &finish);

   int swap = start;
   //This ensures that the start year is always less than the finish year
   if (start > finish) {
       start = finish;
       finish = swap;
   }

   int i = start;
   // This is the loop counter, but it is being abused to actually
   // store the year of interest (which lets allows printf of i)
    
   for (i = start; i < (finish + 1); i++) {
       if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
           printf("%d\n", i);
       }
   }

   return EXIT_SUCCESS;
}
