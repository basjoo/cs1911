/*
 *  Q1.c
 *  10 marks
 *  comp1917 practical-exam 2014s1
 *  redact on a list which does not contain duplicates 
 *
 *  Stub by Richard Buckland on 21 June 2014
 *  
 */ 

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

// given a list "l" which does not contain any duplicates, and given
// a character "secret", remove from the list the node (if any) which 
// has the "secret" character in its value field. 
// 
// Constraints:
// don't malloc any new nodes
// don't free any nodes, even the nodes you remove from the list
// don't change the "value" field of any node, just change links

/* 
  eg given the list 
    "F->R->E->D->*" 
  redacting F would change the list to be 
    "R->E->D->*"

  eg given the list 
    "F->R->E->D->*" 
  redacting D would change the list to be 
    "F->R->E->*"

  eg given the list 
    "F->R->E->D->*" 
  redacting M would leave the list unchanged 
    "F->R->E->D->*"

see the test file for more examples

*/

/* 
compile your code using:
   gcc -Wall -Werror -std=c99 -o q1 -O q1.c testQ1.c
run it using 
   ./q1
*/

void redact (list l, char secret) {
    // insert your code here

    link current = l->head;
    if (current == NULL) {
        return;     //maybe exit(1) here
    }
    if (current == secret) {
        l->head = current->next;
        return;
    }
    if (current->next->data == secret) {
        if (current->next->next != NULL) {
            current->next = current->next->next;
        } else {
            current->next = NULL;
        }
    } else if (current->next == NULL) {
        return;
    } else {
        redact(current->next, secret);
    }

    //Second Attempt
    link current = l->head;
    if (current == NULL) {
        return;
    }

    while (current->next != NULL) {
        if ()
        current = current->next;
    }

    //Beth

    if (l->head == NULL) {
        return;
    }
    link prev = l->head;
    link current = l->head;
    //First case is special (cause updates l->head)
    if (current->value == secret) {
        l->head = current->next
    } else {
        while (current!= NULL && current->value == secret) {       //This only finds the first one
            prev = current;
            current = l->next;
        }
        //set
        if (current != NULL) {
            prev->next = current->next;
        }

    }
}    


