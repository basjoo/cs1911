//Danilo Scodellaro
//z3414551
//23-JUL-2014
//tut16.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct list_node list_node;
typedef list_node *linked_list;

struct list_node {
    int       data;
    list_node *next;
};

//Function Prototypes
int member(int value, linked_list list);
linked_list list_append(linked_list list1, linked_list list2);
linked_list insert_ordered(int item, linked_list list);
linked_list merge_sorted(linked_list list1, linked_list list2);
//Recursive Prototypes
int memberRecursive(int value, linked_list list);
//Copied 

int main(int argc, char const *argv[]) {
    


    memberRecursive()

    return 0;
}

//Functions
linked_list member(int value, linked_list list) {

    linked_list bob = NULL;
    bob = list;

    while (bob != NULL) {
        if (bob->data == value) {
            return bob;
        } else {
            bob = bob->next;
        }
    }

    return 0;
}

linked_list list_append(linked_list list1, linked_list list2) {

    linked_list bob = NULL;
    bob = list1;

    while (bob->data != NULL) {
        bob = bob->next;
    }
    
    bob->next = list2;

}

linked_list insert_ordered(int item, linked_list list) {

    linked_list bob = list;
    linked_list alice = create_node(item);      //Alice is the new node

    if (bob->data >= alice->data) {
        insert(item, bob);
        return bob;
    }

    while (bob->next != NULL && bob->next->data <= alice->data) {
        bob = bob->next;
    }

    alice->next = bob->next;
    bob->next = alice;

    return bob;
}

//Functions Recursively

int memberRecursive(int value, linked_list list) {

    linked_list bob = NULL;
    bob = list;

    if (bob == NULL) {
        return 0;
    } else if (bob->data == value) {
        return 1;
    } else {
        return(member(bob->next));
    }

}


//Copied in 

/*
 * create a list_node and place the specified values in the fields
 */
linked_list create_node(int data) {

    linked_list new_node = malloc(sizeof(struct list_node));        
    if (new_node == NULL) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

/*
 * append integer to end of list
 */
linked_list append(int data, linked_list list) {

    linked_list new_node = create_node(data);
    if (first(list) == NULL) {
        list = new_node;
    } else { 
        last(list)->next = new_node;
    }
    //printf("append ending");
    return list;

}