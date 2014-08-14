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
    char openBracket[3] = {'(', '[', '{'};
    char closeBracket[3] = {')', ']', '}'};
    int temp = 0;
    int i = 0;

    //Create stack
    stack_t bracketStack = create();

    //Loop through all characters until EOF is reached
    while(temp != EOF) {

        //Scan input from stdin and store in temp
        temp = getchar();

        //Check if input is open bracket and handle it
        for (i = 0; i <= 2; i++) {
            if (temp == openBracket[i]) {
                push(bracketStack, temp);
            }
        }

        //Check if input is close bracket and handle it 
        for (i = 0; i <= 2; i++) {
            if (temp == closeBracket[i]) {
                if (is_empty(bracketStack) == 0) {
                    //error(2);       //debug
                    printf("is_empty bracketStack i = %d. is_empty(bracketStack) = %d.\n", i, is_empty(bracketStack));
                    results(1);
                } else if (top(bracketStack) == openBracket[i]) {
                    //error(3);   //debug
                    pop(bracketStack);
                } else {
                    //printf("top is: %d. temp is %d", top(bracketStack), temp);
                    //error(1);   //debug
                    results(1);               
                }
            }
        }
    }

    //Check if stack is empty (if not, then it must be unbalanced)
    if (size(bracketStack) != 0) {
        destroy(bracketStack);
        results(1);
    } else {
        destroy(bracketStack);
        results(0);
    }

    return EXIT_SUCCESS;
}

//Functions
void results(int balance) {
    if (balance == 0) {
        printf("Yes, balanced.\n");
        exit(0);
    } else {
        printf("No, not balanced.\n");
        exit(1);
    }

}

void error(int errorNumber) {
    printf("An error has occurred #%d.\n", errorNumber);
    exit(1);
}
