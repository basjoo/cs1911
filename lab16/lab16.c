//Danilo Scodellaro
//z3414551
//23-JUL-2014
//lab16.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 4096

typedef struct list_node list_node;
typedef list_node *linked_list;

struct list_node {
    int       data;
    list_node *next;
};

//Functions Prototype
linked_list create_node(int data, linked_list next);
linked_list insert(int value, linked_list list);
linked_list last(linked_list list);
linked_list append(int value, linked_list list);
void print_list(linked_list list);

linked_list delete_first(linked_list list);
linked_list delete_last(linked_list list);
linked_list delete(int i, linked_list list);
linked_list reverse(linked_list list);

void destroy_node(linked_list list);
int length(linked_list list);
linked_list member(int value, linked_list list);

//Functions Written
/*
 * delete first node from list
 */
linked_list delete_first(linked_list list) {
	// REPLACE WITH YOUR CODE

    if (length(list) == 0) {
        return list;
    }
    linked_list temp = list->next;
    destroy_node(list);

	return temp;
}

/*
 * delete last node from list
 */
linked_list delete_last(linked_list list) {
    // REPLACE WITH YOUR CODE

    linked_list temp = list;

    if (length(list) <= 1) {
        return(delete_first(list));
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    destroy_node(temp->next);
    temp->next = NULL;

    return list;
}

/*
 * delete first node containing specified int
 */
linked_list delete(int value, linked_list list) {
	// REPLACE WITH YOUR CODE

    linked_list temp = list;
    linked_list tempNode = NULL;    //node->next
    linked_list previous = NULL;

    //Check if list exists
    if (list == NULL) {
        return list;
    }
    
    //Special case to handle if node 1 is a match
    if (list->data == value) {
        return(delete_first(list));
    }

    //Find node containing specified int
    while (temp != NULL) {
        if (temp->data == value) {
            break;
        } else { 
            previous = temp;
            temp = temp->next;
        }
    }
    if (temp == NULL) {
        return list;
    }

    //Make node->back = node->next
    tempNode = temp->next;
    destroy_node(temp);
    previous->next = tempNode;

    return list;
}

/*
 * reverse the nodes in list
 */
linked_list reverse(linked_list list) {
	// REPLACE WITH YOUR CODE

    linked_list forward = NULL;
    linked_list backward = NULL;
    //int middle = NULL;

    while (list != NULL) {
        forward = list->next;
        list->next = backward;
        backward = list;
        list = forward;
    }

    return backward;
}

//The above inspired by:
//http://www.teamten.com/lawrence/writings/reverse_a_linked_list.html

//Main
/*
 * test the above functions
 */
int main(int argc, char *argv[]) {
    linked_list list;
    int argument;
    char *s, *t;
    char line[MAX_LINE];
    char action[MAX_LINE];
    
    list = NULL;
    while (1) {
        printf("list = ");
        print_list(list);
        printf("\n");
        printf("> ");
        if (fgets(line, MAX_LINE, stdin) == NULL)
            break;
        
        for (s = line; isspace(*s); s++)
            ;
        
        t = action;
        while (isalpha(*s) || *s == '_')
            *t++ = *s++;
        *t = '\0';
        
        argument = strtol(s, &s, 10);

        if (strcmp(action, "quit") == 0)
            break;
        else if (strcmp(action, "") == 0)
            continue;
        else if (strcmp(action, "insert") == 0)
            list = insert(argument, list);
        else if (strcmp(action, "append") == 0)
            list = append(argument, list);
        else if (strcmp(action, "delete_first") == 0)
            list = delete_first(list);
        else if (strcmp(action, "delete_last") == 0)
            list = delete_last(list);
        else if (strcmp(action, "delete") == 0)
            list = delete(argument, list);
        else if (strcmp(action, "reverse") == 0)
            list = reverse(list);
        else
            printf("Unknown command: '%s'\n", action);
    }
    return 0;
}

//Functions copied in from tut14

void destroy_node(linked_list list) {
    if (list == NULL) {
        return;
    } else {
        free(list);
    }
}

int length(linked_list list) {

    linked_list bob = NULL;
    bob = list;
    int i = 0;

    if (bob == NULL) {
        return i;       
    }

    while (bob != NULL) {
        i++;
        bob = bob->next;
    }

    return i;   
}

//Functions copied from tut16
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

    return bob;
}

//Functions Given
/*
 * create a list_node and place the specified values in the fields
 */
linked_list create_node(int data, linked_list next) {
    list_node *n;

    n = malloc(sizeof (list_node));
    if (n == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    n->data = data;
    n->next = next;
    return n;
}

/*
 * insert integer at front of list
 */
linked_list insert(int value, linked_list list) {
    return create_node(value, list);
}

/*
 * return pointer to last node in list
 * NULL is returned if list is empty
 */
linked_list last(linked_list list) {
    list_node *n = list;
    if (n == NULL)
        return NULL;
    while (n->next != NULL)
        n = n->next;
    return n;
}


/*
 * append integer to end of list
 */
linked_list append(int value, linked_list list) {
    list_node *n;

    n =  create_node(value, NULL); /* will be last node in list */

    if (list == NULL) {
       return n;                  /* new node is now  head of the list */
    } else {
        last(list)->next = n;  /* append node to list */
        return list;
    }
}

/*
 * print contents of list in Python syntax
 */
void print_list(linked_list list) {
    list_node *n;
    
    printf("[");
    for (n = list; n != NULL; n = n->next) {
        printf("%d", n->data);
        if (n->next != NULL)
            printf(", ");
    }
    printf("]");
}