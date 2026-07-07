#include "Board.h"
#include <iostream>

int main() {
    Board board;
    int currentPlayer = 1;

    while (true) {
        board.print();
        std::cout << "Player " << currentPlayer << ", choose a column (0-6): ";

        int col;
        std::cin >> col;

        bool success = board.dropPiece(col, currentPlayer);
        if (!success) {
            std::cout << "Invalid move, try again." << std::endl;
            continue;
        }

        int winner = board.checkWinner();
        if (winner != 0) {
            board.print();
            std::cout << "Player " << winner << " wins!" << std::endl;
            break;
        }

        if (board.isBoardFull()) {
            board.print();
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}