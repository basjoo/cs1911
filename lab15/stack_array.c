#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_ARRAY 100

struct stack {
    int data[MAX_ARRAY];
    int top;
};

// create a new stack
stack_t create(void) {

    stack_t stack = malloc(sizeof(struct stack));
    stack->top = 0;

    return stack;
}

// add new item to stack
void push(stack_t stack, int item) {
    //printf("top is: %d\n", stack->top);
    if (is_empty(stack) == 0) {
        stack = create();
        printf("test\n");
    } else if (stack->top == MAX_ARRAY) {
        fprintf(stderr, "stack capacity reached\n");
        exit(1);
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

    for (i = 0; i < MAX_ARRAY && i != 0; i++) {

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
