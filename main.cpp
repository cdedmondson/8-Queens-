/*******************************************************************
*
*   File: main.cpp
*   Author: Cameron Edmondson
*   Class: CS 4200
*   Assignment: program 1
*   Date last modified: 09/20/2019
*
*   Problem: Position n queens on a chessboard so that no two are in the same row, column,
*            or diagonal.
*
*   Inputs: Positive integer n
*
*   Outputs: All possible ways n queens can be placed on an n × n chessboard so that no two
*           queens threaten each other.
*
*   Example output solution:
*
*   + - - - - - - - - +
*   | + + + + + + Q + |
*   | + + + + Q + + + |
*   | + + Q + + + + + |
*   | Q + + + + + + + |
*   | + + + + + Q + + |
*   | + + + + + + + Q |
*   | + Q + + + + + + |
*   | + + + Q + + + + |
*   + - - - - - - - - +
*
* *****************************************************************/

#include <iostream>

using namespace std;

const int n = 8;    // Chessboard size
int col[n]; // Create and initialize array of 8 columns
char board[n][n];   // Initialize n x n chessboard

bool promising(int i);

//################################ Initialize Board Begin ################################
/*
 * Function: initializeBoard
 * Purpose: Iterate through each row and column of
 * chessboard initializing each element with "+".
 */
void initializeBoard() {

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            board[row][col] = '+';
        }
    }

}
//################################ Initialize Board End ##################################

//################################ Print Board Begin #####################################
/*
 * Function: printBoard
 * Purpose: Iterate through each row and column displaying
 * either a "+" symbol which represents a checker box or
 * "Q" which represents a Queen.
 */
void printBoard() {

    cout << "+ - - - - - - - - +\n";
    for (int i = 1; i <= n; i++) {
        cout << "| ";
        board[i][col[i]] = 'Q';
        for (int j = 1; j <= n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "|";
        cout << "\n";
    }
    cout << "+ - - - - - - - - +\n";

}
//################################ Print Board End #######################################

//################################ Queens Begin ##########################################
/*
 * Function: queens
 * Purpose: Check if leaf is promising, if it is, initialize
 * the chessboard and print results.  Else recursively prune
 * subtree.
 */
void queens(int i) {

    int j;

    if (promising(i)) {
        // If i == n we reached a promising leaf.
        // i.e. we are at a solution
        if (i == n) {
            initializeBoard();
            printBoard();
        } else {
            // Check if queen in [i + 1] row can be
            // positioned in each of the "n" columns
            for (j = 1; j <= n; j++) {
                col[i + 1] = j;
                queens(i + 1);
            }
        }
    }
}
//################################ Queens End ############################################

//################################ Promising Begin #######################################
/*
 * Function: promising
 * Purpose: Returns true when the dummy node is passed: 0 < k’s initial value.
 * Returns false if any of the previously placed queens are in the same column as the
 * queen in row "i" or if they are on the same diagonal; true otherwise
 */
bool promising(int i) {
    int k = 1;
    bool queenIsSafe = true;

    // Check all previously selected queens to ensure none threaten queen in row "i".
    while (k < i && queenIsSafe) {
        if (col[i] == col[k] || abs(col[i] - col[k]) == i - k) {
            queenIsSafe = false;
        }
        k++;
    }
    return queenIsSafe;
}
//################################ Promising End #######################################

//################################ Main Begin ##########################################
int main() {

    // Pass queens function "0" which represents a dummy node
    queens(0);

    return 0;
}
//################################ Main End ############################################