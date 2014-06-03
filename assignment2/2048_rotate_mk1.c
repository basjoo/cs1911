// Author: Danilo Scodellaro
// z3414551
// Date created: 01-JUN-2014
// Date submitted: 02-JUN-2014
// cs1911
// Assignment 2 - 2048
// 2048.C

// DESCRIPTION
// Program implements the recently developed game 2048
// Javascript web application available at:
// "http://gabrielecirulli.github.io/2048/"

// CONSTRAINTS
// The incomplete file 2048.c is provided as a starting point
// Some parts of the program cannot be edited
// Specifically: main, insertNewNumber, printHelp
// 8 functions MUST be implemented (type cannot change)
// Specifically: moveXXXX, boardContains2048, printBoard, readBoard
// insertNewNumber depends on vacant squares containing the value 0
// Code must work if the SIZE constant is changes (see #define)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define SIZE 4
#define GOAL 2048       //Can change if you don't want 2048 to be the goal tile

// Function Prototypes

int moveLeft(int board[SIZE][SIZE]);
int moveRight(int board[SIZE][SIZE]);
int moveDown(int board[SIZE][SIZE]);
int moveUp(int board[SIZE][SIZE]);
int gameOver(int board[SIZE][SIZE]);
int boardContains2048(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE]);
int readBoard(int board[SIZE][SIZE]);
void printHelp(void);                           //DO NOT MODIFY
void insertNewNumber(int board[SIZE][SIZE]);    //DO NOT MODIFY
void rotateBoard(int board[SIZE][SIZE]);        //Original Function

// The functions moveLeft, moveRight, moveUp, moveDown
// return -1 if the specified moving numbers  is not possible.
// Otherwise they move the numbers as indicated and return 
// the change to the score from combining adjacent identical numbers.
// They return 0 if no numbers were combined.

void rotateBoard(int board[SIZE][SIZE]) {

    //Initialise Variables
    int i = 0;
    int j = 0;
    int boardTemp[SIZE][SIZE] = {{0}};

    //Rotate board 90 degrees
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            boardTemp[i][j] = board[SIZE-j-1][i];
        }
    }

    //Write back over board
    for (j = 0; j < SIZE; j++) {
        for (i = 0; i < SIZE; i++) {
            board[i][j] = boardTemp[i][j];
        }
    }    
}

int moveLeft(int board[SIZE][SIZE]) {

    //Initialise Variables
    int moveResult = 0;

    //Rotate Board 2x
    rotateBoard(board);
    rotateBoard(board);

    //Call moveRight
    moveResult = moveRight(board);

    //Rotate Back
    rotateBoard(board);
    rotateBoard(board);

    //Return score to main
    return moveResult;
}

int moveRight(int board[SIZE][SIZE]) {

    //Initialise Variables
    int i = 0;
    int j = 0;
    int moveScore = 0;
    int changeFlag = 1;
    int changeCounter = 0;

    //Move Right (Shift to edge)
    changeFlag = 1;
    while (changeFlag == 1) {
        changeFlag = 0;
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (j == SIZE - 1 || board[i][j] == 0) {
                    continue;
                } else if (board[i][j+1] == 0) {
                    board[i][j+1] = board[i][j];
                    board[i][j] = 0;
                    changeFlag = 1;
                    changeCounter = changeCounter + 1;
                }
            }
        }
    }

    //Move Right (Additive)
    for (i = 0; i < SIZE; i++) {
        for (j = SIZE - 1; j >= 0; j--) {
            if (j == SIZE - 1 || board[i][j] == 0) {
                continue;
            } else if (board[i][j] == board[i][j+1]) {
                board[i][j+1] = 2*board[i][j+1];
                board[i][j] = 0;
                moveScore = moveScore + board[i][j+1];
            }
        }
    }

    //Move Right (Shift to edge)
    changeFlag = 1;
    while (changeFlag == 1) {
        changeFlag = 0;
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (j == SIZE - 1 || board[i][j] == 0) {
                    continue;
                } else if (board[i][j+1] == 0) {
                    board[i][j+1] = board[i][j];
                    board[i][j] = 0;
                    changeFlag = 1;
                    changeCounter = changeCounter + 1;
                }
            }
        }
    }

    //Return score to main
    if (moveScore == 0 && changeCounter == 0) {
        return -1; 
    } else {
        return moveScore;
    } 
}

int moveDown(int board[SIZE][SIZE]) {

    //Initialise Variables
    int moveResult = 0;

    //Rotate Board 3x
    rotateBoard(board);
    rotateBoard(board);
    rotateBoard(board);

    //Call moveRight
    moveResult = moveRight(board);

    //Rotate Back
    rotateBoard(board);

    //Return score to main
    return moveResult;
}

int moveUp(int board[SIZE][SIZE]) {

    //Initialise Variables
    int moveResult = 0;

    //Rotate Board 3x
    rotateBoard(board);

    //Call moveRight
    moveResult = moveRight(board);

    //Rotate Back
    rotateBoard(board);
    rotateBoard(board);
    rotateBoard(board);

    //Return score to main
    return moveResult;
}

// gameOver returns 0 iff it is possible to make a move on the board
// It returns 1 otherwise.

int gameOver(int board[SIZE][SIZE]) {

    //Initialise Variables
    int i = 0;
    int j = 0;
    int boardClone[SIZE][SIZE] = {{0}};
    int moveScore = 0;

    //Copy board to boardClone
    for (j = 0; j < SIZE; j++) {
        for (i = 0; i < SIZE; i++) {
            boardClone[i][j] = board[i][j];
        }
    }

    //Attempt all moves on boardClone
    moveScore = moveScore + moveLeft(boardClone);
    moveScore = moveScore + moveDown(boardClone);
    moveScore = moveScore + moveUp(boardClone);
    moveScore = moveScore + moveRight(boardClone);

    //Return score to main
    if (moveScore == -4) {
        return 1; 
    } else {
        return 0;
    } 

}

// boardContains2048 returns 1 iff the board contains 2048.
// It returns 0 otherwise.

int boardContains2048(int board[SIZE][SIZE]) {

    //Initialise Variables
    int i = 0;
    int j = 0;

    //Check if board contains GOAL(2048)
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {   
            if ((board[i][j]) == GOAL) {
                return 1;
            }
        }
    } 

    return 0;
}

// printBoard displays the board.

void printBoard(int board[SIZE][SIZE]) {

    //Initialise Variables
    int i = 0;
    int j = 0;
    char zero = '.';
    int k = 0;          //Border Counter
    int m = 0;          //Empty Space Counter

    //Print Top Border
    printf("+");
    for (k = 0; k < SIZE; k++) {
        printf("------");
    }
    printf("+\n");

    //Print Board
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (j == 0) {
                printf("|");
            }
            if (board[i][j] == 0) {
                printf("%5c ", zero);
            } else {
                printf("%5d ", board[i][j]);
            }
            if (j == SIZE - 1) {
                printf("|\n");
            }
        }

        //Print Empty Line
        if (i != SIZE - 1) {
            printf("|     ");
            for (m = 1; m < SIZE; m++){
                printf("      ");
            }
            printf(" |\n");
        }
    }

    //Print Bottom Border
    printf("+");
    for (k = 0; k < SIZE; k++) {
        printf("------");
    }
    printf("+\n");
}

// readBoard attempts to read SIZE*SIZE integers into array board
// it returns how many integers actually were read

int readBoard(int board[SIZE][SIZE]) {

    //Initialise Variables
    int i = 0;
    int j = 0;
    int numbersRead = 0;

    //Load user input into board array
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
            numbersRead = numbersRead + 1;            
        }
    }    

    return numbersRead;
}

// DO NOT MODIFY CODE BELOW THIS LINE 
// Code not modified to remain under 80 column limit - currently exceeds limit

int main(int argc, char *argv[]) {
    int board[SIZE][SIZE] = {{0}};
    int c, score, moveScore, gameWon, numbersRead;
    unsigned int seed;
    
    // initialize random generator with command-line argument if provided
    // or with current time
    if (argc > 1){
        seed = atoi(argv[1]);
    } else {
        seed = time(0);
    }
    srand(seed);

    printf("Enter %d numbers making up initial board:\n", SIZE * SIZE);
    numbersRead = readBoard(board);
    if (numbersRead != SIZE * SIZE) {
        printf("Warning readBoard read only %d numbers\n", numbersRead);
    }

    printf("Repeat game by running: %s %u\n", argv[0], seed);
    printHelp();
    score = 0;
    gameWon = 0;
    while (gameOver(board) == 0) {
        printf("\n");
        printBoard(board);
        printf("Your score is %d.\n", score);   
        if (gameWon == 0 && boardContains2048(board)) {
            gameWon = 1;
            printf("Congratulations you've won the game - q to quit or you can keep going\n");
        }
        printf("> ");
        
        c = getchar();
        while (c != EOF && isspace(c)) {
            c = getchar();
        }
        
        printf("\n");
        
        if (c == EOF || c == 'q' || c == 'Q') {
            printf("Good bye - your final score was %d.\n", score); 
            return 1;
        }

        c = tolower(c);
        if (!strchr("hjklaswd", c)) {
            printHelp();
        } else {
            moveScore = 0;
            if (c == 'h' || c == 'a') {
                moveScore = moveLeft(board);
            } else if (c == 'j' || c == 's') {
                moveScore = moveDown(board);
            } else if (c == 'k' || c == 'w') {
                moveScore = moveUp(board);
            } else if (c == 'l' || c == 'd') {
                moveScore = moveRight(board);
            }

            if (moveScore == -1) {
                printf("%c is not a legal move in the current position.\n", c); 
            } else {
                insertNewNumber(board);
                score = score + moveScore;
            }
        } 
    }
    printBoard(board);
    printf("Game over - your final score was %d.\n", score);    
    return 0;
}

// print a help message
// do not change this function

void printHelp(void) {
    printf("Enter h or a for left, j or s for down, k or w for up, l or d for right, q to quit\n");
}

// add a new number to the board
// it will either be a 2 (90% probability) or a 4 (10% probability)
// do not change this function

void insertNewNumber(int board[SIZE][SIZE]) {
    int row, column;
    int index, availableSquares = 0;
    
    // count vacant squares
    for (row = 0; row < SIZE; row = row + 1) {
        for (column = 0; column < SIZE; column = column + 1) {
            if (board[row][column] == 0) {
                availableSquares = availableSquares + 1;
            }
        }
    }

    if (availableSquares == 0) {
        printf("Internal error no available square\n");
        exit(1);
    }

    // randomly pick a vacant square
    index = rand() % availableSquares;
    for (row = 0; row < SIZE; row = row + 1) {
        for (column = 0; column < SIZE; column = column + 1) {
            if (board[row][column] == 0) {
                if (index == 0) {
                    if (rand() % 10 == 0) {
                        board[row][column] = 4;
                    } else {
                        board[row][column] = 2;
                    }
                    return;
                }
                index = index - 1;
            }
        }
    }
}