/*
 *  backToFront.c
 *  pracExam 2011
 *
 *  This solution by David Collien 20/06/11. (tweaked by rb 2013)
 *  
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "backToFront.h"

nodePtr backToFront (nodePtr oldList) {
   
   nodePtr newList;
      
   if ((oldList==NULL) || (oldList->next==NULL)) {
      // 0 or 1 items in the list
      newList = oldList;
      
   } else {
      nodePtr current = oldList;
      nodePtr secondLast;

      while (current->next != NULL) {
         if (current->next->next == NULL) {
            secondLast = current;
         }
         current = current->next;
      }
      nodePtr last = current;
      
      // make second last the last one by NULL terminating it
      secondLast->next = NULL;
      
      // insert last at the front
      newList = last;
      newList->next = oldList;
   }
   
   return newList;
}
