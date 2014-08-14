/*
 *  Q2.c
 *  10 marks
 *  comp1917 practical-exam 2014s1
 *  redact on a list which CAN contain duplicates 
 *  - same as Q1 except the input list might now contain duplicates
 *  Stub by Richard Buckland on 21 June 2014
 *  
 */ 

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

// given a list "l" which might or might not contain any duplicates, 
// and given a character "secret", remove from the list any node 
// which has the "secret" character in its value field.  
// Constraints:
// don't malloc any new nodes
// don't free any nodes, even the nodes you remove from the list
// don't change the "value" field of any node, just change links


/* 
  eg given the list 
    "F->F->R->E->D->*" 
  redacting F would change the list to be 
    "R->E->D->*"

  eg given the list 
    "F->E->R->E->D->*" 
  redacting E would change the list to be 
    "F->R->D->*"

  eg given the list 
    "F->R->E->D->D->D*" 
  redacting M would leave the list unchanged 
    "F->R->E->D->D->D*"

see the test file for more examples
*/

/* 
compile your code using:
   gcc -Wall -Werror -std=c99 -o q2 -O q2.c testQ2.c
run it using 
   ./q2
*/

void redact (list l, char secret) {
    // insert your code here
}    


