#include "Board.h"
#include "Minimax.h"
#include <iostream>

int main() {
    Board board;
    int currentPlayer = 1;
    int searchDepth = 5;

    while (true) {
        board.print();

        int col;
        if (currentPlayer == 1) {
            std::cout << "Player 1, choose a column (0-6): ";
            std::cin >> col;
        } else {
            std::cout << "AI (Player 2) is thinking..." << std::endl;
            col = findBestMove(board, searchDepth, currentPlayer);
            std::cout << "AI chose column " << col << std::endl;
        }

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