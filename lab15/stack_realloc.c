#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define SIZE 5

struct stack {
    int *data;
    int top;
    int max;
};

void expand(stack_t stack);

// create a new stack
stack_t create(void) {

    stack_t stack = malloc(sizeof(struct stack));
    stack->data = malloc(SIZE*sizeof(int));
    stack->top = 0;
    stack->max = SIZE;

    return stack;
}

// add new item to stack
void push(stack_t stack, int item) {
    //printf("top is: %d\n", stack->top);
    if (is_empty(stack) == 0) {
        stack = create();
        printf("test\n");
    } else if (stack->top == stack->max - 1) {
        expand(stack);          //Separate function to realloc
        printf("Realloced!\n");
    } 
    stack->top = stack->top + 1;
    stack->data[stack->top] = item;
    //printf("top is: %d\n", stack->top);
}

// remove top item from stack and return it
int pop(stack_t stack) {
    //printf("Welcome to pop\n");
    if (is_empty(stack) == 0) {
        return 0;
    }

    int temp = stack->data[stack->top];
    stack->data[stack->top] = 0;
    //free(stack->data[stack->top]);        //Not sure what to do about freeing here
    stack->top = stack->top - 1;
    //printf("You have left pop\n");
    return temp;

}

// return true if stack is empty
int is_empty(stack_t stack) {
    //printf("Welcome to is_empty. stack->top is %d.\n", stack->top);
    if (stack->top == -1) {
        return 0;
    } else {
        return 1;
    }

}

// return top item from stack but don't remove it
int top(stack_t stack) {
    //printf("Welcome to top()\n");
    if (is_empty(stack) == 0) {
        fprintf(stderr, "top() of empty stack\n");
        exit(1);
    }
    return stack->data[stack->top];
}

// return number elements in stack   
int size(stack_t stack) {
    //printf("Welcome to size\n");
    int i = 0;

    for (i = 0; i < stack->max && i != 0; i++) {

    }
    return i;
}
             
// free a stack
void destroy(stack_t stack) {
    //printf("Welcome to destroy\n");
    while (!is_empty(stack)) {
        pop(stack);
    }
    free(stack);
}

// realloc space to a maxxed out array 
void expand(stack_t stack) {
    printf("First 98\n");
    stack->max = stack->max + SIZE;
    int *temp = realloc(stack->data, (stack->max)*sizeof(int));
    printf("Second 100\n");
    if (temp == NULL) {
        printf("Third 102\n");
        fprintf(stderr, "Realloc has failed given stack = %p, stack->data = %p, stack->top = %d, stack->max = %d.\n", stack, stack->data, stack->top, stack->max);
        printf("Fourth 104\n");
        exit(1);
        printf("Fifth 106\n");
    } else {
        printf("Sixth 108\n");
        stack->data = temp;
        stack->max = stack->max + SIZE;
        printf("Seventh 110\n");
    }

    return;
}
