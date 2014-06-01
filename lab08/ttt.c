// Author: Danilo Scodellaro
// z3414551
// Date created: 29-APR-2014
// Date submitted: 31-APR-2014
// cs1911
// lab08 - ttt.c

// DESCRIPTION
// Program takes a 2D 'Noughts and Crosses' array from the user, prints 
// it out and determines if there are any winners

// ASSUMPTIONS & CONSTRAINTS
// All arrays will be 'valid' games (only one winner)
// The game matrix will be a 3x3 standard 'Noughts and Crosses' setup
// But code must be easily editable to different sized (2D) games

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NOUGHT 0
#define CROSS 1
#define EMPTY 2
#define SIZE 3

int main(int argc, char const *argv[]) {

    //Define Variables
    int i = 0;                      //Loop Counter
    int j = 0;                      //Loop Counter
    int winner = EMPTY;             //Stores which player won
    int oCount = 0;                 //# of noughts 
    int xCount = 0;                 //# of crosses
    int board[SIZE][SIZE];          //Game matrix input by user
    char visualConvert[] = {'O', 'X', '.', '\0'};   //Conversion array

    //Request user input
    printf("Please enter the board:\n");

    //Store user input
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);            
        }
    }    

    //Determine Winner of Rows
    for (i = 0; i < SIZE; i++) {
        oCount = 0;
        xCount = 0;
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == NOUGHT) {
                oCount = oCount + 1;
            } else if (board[i][j] == CROSS) {
                xCount = xCount + 1;
            }
        }

        if (oCount == SIZE) {
            winner = NOUGHT;
        } else if (xCount == SIZE) {
            winner = CROSS;
        }
    }

    //Determine Winner of Columns
    for (j = 0; j < SIZE; j++) {
        oCount = 0;
        xCount = 0;
        for (i = 0; i < SIZE; i++) {
            if (board[i][j] == NOUGHT) {
                oCount = oCount + 1;
            } else if (board[i][j] == CROSS) {
                xCount = xCount + 1;
            }
        }

        if (oCount == SIZE) {
            winner = NOUGHT;
        } else if (xCount == SIZE) {
            winner = CROSS;
        }
    }

    //Determine Winner of Down-sloping Diagonal
    oCount = 0;
    xCount = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == NOUGHT && i == j) {
                oCount = oCount + 1;
            } else if (board[i][j] == CROSS && i == j) {
                xCount = xCount + 1;
            }
        }

        if (oCount == SIZE) {
            winner = NOUGHT;
        } else if (xCount == SIZE) {
            winner = CROSS;
        }
    }

    //Determine Winner of Up-sloping Diagonal
    oCount = 0;
    xCount = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == NOUGHT && i == SIZE - j - 1) {
                oCount = oCount + 1;
            } else if (board[i][j] == CROSS && i == SIZE - j - 1) {
                xCount = xCount + 1;
            }
        }

        if (oCount == SIZE) {
            winner = NOUGHT;
        } else if (xCount == SIZE) {
            winner = CROSS;
        }
    }

    //Print user input
    printf("Here is the board:\n\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", visualConvert[board[i][j]]);
            if (j == SIZE - 1) {
                printf("\n");
            }
        }
    }
    printf("\n");


    //Declare Winner
    if (winner == EMPTY) {
        printf("There are no winners\n");
    } else if (winner == NOUGHT) {
        printf("Noughts win\n");
    } else if (winner == CROSS) {
        printf("Crosses win\n");
    }

    return EXIT_SUCCESS;
}