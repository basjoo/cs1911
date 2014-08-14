//Danilo Scodellaro
//z3414551
//22-JUL-2014
//balanced.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "stack.h"

//Function Prototypes
void results(int balance);
void error(int errorNumber);

int main(int argc, char const *argv[]) {

    //Define Variables
    char openBracket[3][1] = {"(", "[", "{"};
    char closeBracket[3][1] = {")", "]", "}"};
    char temp = 0;
    int i = 0;

    //Create stack
    stack_t bracketStack = create();

    //Loop through all characters until EOF is reached
    while(temp != EOF) {

        //Scan input from stdin and store in temp
        temp = getchar();

        //Check if input is open bracket or closed and handle it
        for (i = 0; i < 2; i++) {
            if (temp == openBracket[i]) {
                push(stack_t bracketStack, atoi(temp));
            } else if (temp == closeBracket[i]) {
                if (top(stack_t bracketStack) == temp) {
                    pop(stack_t bracketStack);
                } else {
                    results(1);
                }
            }
        }
    }

    //Check if stack is empty (if not, then it must be unbalanced)
    if (size(stack_t bracketStack) != 0) {
        destroy(stack_t bracketStack);
        results(1);
    } else {
        destroy(stack_t bracketStack);
        results(0);
    }

    return EXIT_SUCCESS;
}

//Functions
void results(int balance) {
    if (balance == 0) {
        printf("Yes, balanced.");
        exit(0);
    } else {
        printf("No, not balanced.");
        exit(1);
    }

}

void error(int errorNumber) {
    printf("An error has occurred #%d.\n", errorNumber);
    exit(1);
}
