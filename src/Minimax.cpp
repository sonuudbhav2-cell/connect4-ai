#include "Board.h"
#include <algorithm>
#include "Minimax.h"

int minimax(Board board, int depth, int alpha, int beta, bool isMaximizing) {
    int winner = board.checkWinner();
    if (winner == 1) return 1;
    if (winner == 2) return -1;
    if (board.isBoardFull()) return 0;
    if (depth == 0) return 0;

    if (isMaximizing) {
        int bestScore = -1000;
        for (int col = 0; col < Board::COLS; col++) {
            if (board.isColumnFull(col)) continue;

            Board child = board;
            child.dropPiece(col, 1);
            int score = minimax(child, depth - 1, alpha, beta, false);
            bestScore = std::max(bestScore, score);

            alpha = std::max(alpha, bestScore);
            if (alpha >= beta) break;   // prune!
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int col = 0; col < Board::COLS; col++) {
            if (board.isColumnFull(col)) continue;

            Board child = board;
            child.dropPiece(col, 2);
            int score = minimax(child, depth - 1, alpha, beta, true);
            bestScore = std::min(bestScore, score);

            beta = std::min(beta, bestScore);
            if (alpha >= beta) break;   // prune!
        }
        return bestScore;
    }
}

int findBestMove(Board board, int depth, int player) {
    int bestScore = (player == 1) ? -1000 : 1000;
    int bestCol = -1;
    bool nextIsMaximizing = (player != 1);

    for (int col = 0; col < Board::COLS; col++) {
        if (board.isColumnFull(col)) continue;

        Board child = board;
        child.dropPiece(col, player);
        int score = minimax(child, depth - 1, -1000, 1000, nextIsMaximizing);

        bool better = (player == 1) ? (score > bestScore) : (score < bestScore);
        if (better) {
            bestScore = score;
            bestCol = col;
        }
    }

    return bestCol;
}