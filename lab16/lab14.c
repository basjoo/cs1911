//Danilo Scodellaro
//z3414551
//21-JUL-2014
//lab14.c

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

/*
 * return 1 iff list contains no elements, 0 otherwise
 */
int is_empty(linked_list list) {

	if (list == NULL) {
		return 1;
	} else {
		return 0;
	}

}

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
 * insert integer at front of list
 */
linked_list insert(int data, linked_list list) {

	linked_list new_node = malloc(sizeof(struct list_node));		
	if (new_node == NULL) {
		fprintf(stderr, "Error: memory allocation failed.\n");
		exit(1);
	}
	new_node->data = data;
	new_node->next = list;

	return new_node;
}

/*
 * return pointer to first node in list
 * NULL is returned if list is empty
 */
linked_list first(linked_list list) {
	//printf("YOU'VE REACHED FIRST!\n");
	return list;

}

/*
 * return pointer to last node in list
 * NULL is returned if list is empty
 */
linked_list last(linked_list list) {

	linked_list bob;
	bob = list;
	if (bob == NULL) {
		return bob;		
	}

	while (bob->next != NULL) {
		bob = bob->next;
	}

	return bob;
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

/*
 * print contents of list in Python syntax
 */
void print_list(linked_list list) {

	linked_list bob = NULL;
	bob = list;
	if (bob == NULL) {
		return;		
	}
	printf("[");
	while (bob != NULL) {
		printf("%d", bob->data);
		if (bob->next != NULL) {
			printf(", ");
		}
		bob = bob->next;
	}
	printf("]");
	return;	
}

/*
 * return number of nodes in list
 */
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

/*
 * return sum of node data in list
 */
int sum(linked_list list) {

	linked_list bob = NULL;
	bob = list;
	int sum = 0;

	if (bob == NULL) {
		return sum;		
	}

	while (bob != NULL) {
		sum = sum + bob->data;
		bob = bob->next;
	}

	return sum;
}

/*
 * return pointer to nth node in list, counting from 0
 */
linked_list nth(int index, linked_list list) {

	linked_list bob = NULL;
	bob = list;
	int i = 0;
	if (bob == NULL) {
		return bob;		
	}

	while (i < index) {
		bob = bob->next;
		i++;
	}

	return bob;
}

/*
 * return pointer to middle node in list
 */
linked_list middle(linked_list list) {

	//printf("YOU'VE REACHED MIDDLE\n");
	int height = length(list);
	int half = (height/2);		//If even no.of nodes, points to last node
	//printf("Height is %d, half is %d.\n", height, half);
	
	//linked_list bob = nth(half, list);
	//printf("bob->data is %d; bob->next is %d.\n", bob->data, bob->next);
	return nth(half, list);
	//return list;
}

/*
 * return 1 iff the list is in ascending order 
 */
int is_ascending(linked_list list) {

	linked_list bob = NULL;
	bob = list;
	int n = 0;

	if (bob == NULL) {
		return 0;		
	}

	n = bob->data;
	while (bob != NULL) {
		if (bob->data >= n) {
			n = bob->data;
		} else {
			return 0;
		}
		bob = bob->next;
	}

	return 1;
}

void destroy_node(linked_list list) {
	if (list == NULL) {
		return;
	} else {
		free(list);
	}
}

void destroy_list(linked_list list) {

	if (list == NULL) {
		return;		
	}

	while (list != NULL) {
		destroy_node(last(list));
	}
}
/*
 * test the above functions
 */
int
main(int argc, char *argv[]) {
    linked_list list = NULL;
    int number;
    
	printf("Enter a number: ");
	while (scanf("%d", &number) == 1) {
		list =  append(number, list);
		printf("Enter a number: ");
	}
	if (is_empty(list)) {
		printf("List is empty.\n");
		return 0;
	}
	printf("\nList entered was: ");
	print_list(list);
	printf("\nFirst element in list is: %d.\n", first(list)->data);
	printf("Middle element in list is: %d.\n", middle(list)->data);
 	printf("Last element in list is: %d.\n", last(list)->data);
	printf("Length of list is: %d.\n", length(list));
	printf("Sum of the list is: %d.\n", sum(list));
	if (is_ascending(list)) {
		printf("List is in ascending order.\n");
	} else {
		printf("List is not in ascending order.\n");
	}
	return 0;
}

