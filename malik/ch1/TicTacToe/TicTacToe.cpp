#include <string>
#include <iostream>
#include <cstdlib>
#include "TicTacToe.h"

TicTacToe::TicTacToe() {
    char pointNums[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    player1Symbol = 'X';
    player2Symbol = 'O';
    moveCount = 0;
    const int numRows = 3, numCols = 3;

    int count = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            board[i][j] = pointNums[count++];
        }
    }
}

void TicTacToe::getIndexes(int pointSelected, int& row, int& col) {
    std::cout << "Here is the point selected:" << pointSelected << std::endl;
    if (1 <= pointSelected && pointSelected <= 3) {
        row = 0;
        col = pointSelected - 1;
    } else if (4 <= pointSelected && pointSelected <= 6) {
        row = 1;
        col = pointSelected - 4;
    } else if (7 <= pointSelected && pointSelected <= 9) {
        row = 2;
        col = pointSelected - 7;
    }
}

void TicTacToe::printBoard() {
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "\t\t|\t" << "\t|\t\t" << std::endl;
    std::cout << "\t" << board[0][0] << "\t|\t" << board[0][1] << "\t|\t" << board[0][2] << std::endl;
    std::cout << "\t\t|\t" << "\t|\t\t" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "\t\t|\t" << "\t|\t\t" << std::endl;
    std::cout << "\t" << board[1][0] << "\t|\t" << board[1][1] << "\t|\t" << board[1][2] << std::endl;
    std::cout << "\t\t|\t" << "\t|\t\t" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "\t\t|\t" << "\t|\t\t" << std::endl;
    std::cout << "\t" << board[2][0] << "\t|\t" << board[2][1] << "\t|\t" << board[2][2] << std::endl;
    std::cout << "\t\t|\t" << "\t|\t\t" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

void TicTacToe::play() {
    bool isPlayer1Move = true;
    int move = INVALID_MOVE;
    int col = -1;
    int row = -1;

    do {
        if (system("CLS")) system("clear");

        std::cout << "\n\t\t You (" << (isPlayer1Move ? player1Symbol : player2Symbol) << ")" << std::endl;
        printBoard();

        getMove(move);

        getIndexes(move, row, col);
        board[row][col] = (isPlayer1Move ? player1Symbol : player2Symbol);
        isPlayer1Move = !isPlayer1Move;
        move = INVALID_MOVE;
        moveCount++;

    } while (isOver() == false);

    if (system("CLS")) system("clear");
    printBoard();

    if (isDraw()) {
        std::cout << "The match ended with a draw" << std::endl;
    } else if (playerWon(player1Symbol)) {
        std::cout << "Player one (" << player1Symbol << ") won the match!" << std::endl;
    } else {
        std::cout << "Player two (" << player2Symbol << ") won the match!" << std::endl;
    }


}

void TicTacToe::getMove(int &move) const {
    int selectionCount = 0;

    while ((1 <= move && move <= 9) == false) {
        if (selectionCount > 0) {
            std::cout << std::endl;
            std::cout << "That move is not valid. Please try again." << std::endl;
        }
        std::cout << "Please select a slot (Number from 1-9 only): " << std::endl;
        std::cin >> move;

        selectionCount++;
    }
}

bool TicTacToe::isDraw() const {
    return playerWon(player1Symbol) == false && playerWon(player2Symbol) == false;
}

bool TicTacToe::playerWon(const char playerToken) const {

    return (board[0][0] == playerToken && board[0][1] == playerToken && board[0][2] == playerToken) ||
            (board[1][0] == playerToken && board[1][1] == playerToken && board[1][2] == playerToken) ||
            (board[2][0] == playerToken && board[2][1] == playerToken && board[2][2] == playerToken) ||
            // vertical winning combo
            (board[0][0] == playerToken && board[1][0] == playerToken && board[2][0] == playerToken) ||
            (board[0][1] == playerToken && board[1][1] == playerToken && board[2][1] == playerToken) ||
            (board[0][2] == playerToken && board[1][2] == playerToken && board[2][2] == playerToken) ||
            // diagonal winning combo
            (board[0][0] == playerToken && board[1][1] == playerToken && board[2][2] == playerToken) ||
            (board[2][0] == playerToken && board[1][1] == playerToken && board[0][2] == playerToken);
}

bool TicTacToe::isOver()  {
    return (moveCount >= MAX_MOVES) || (playerWon(player1Symbol) || playerWon(player2Symbol));
}