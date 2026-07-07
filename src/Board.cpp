#include "Board.h"
#include <iostream>

Board::Board() {
    grid = std::vector<std::vector<int>>(ROWS, std::vector<int>(COLS, 0));
}

bool Board::isColumnFull(int col) const {
    return grid[0][col] != 0;
}

bool Board::dropPiece(int col, int player) {
    if (col < 0 || col >= COLS) return false;
    if (isColumnFull(col)) return false;

    for (int row = ROWS - 1; row >= 0; row--) {
        if (grid[row][col] == 0) {
            grid[row][col] = player;
            return true;
        }
    }
    return false;
}

void Board::print() const {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            char symbol = '.';
            if (grid[row][col] == 1) symbol = 'X';
            if (grid[row][col] == 2) symbol = 'O';
            std::cout << symbol << ' ';
        }
        std::cout << std::endl;
    }
}

int Board::checkWinner() const {
    int dr[4] = {0, 1, 1, 1};   // direction vectors: horizontal, vertical, diag-down-right, diag-down-left
    int dc[4] = {1, 0, 1, -1};

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int player = grid[row][col];
            if (player == 0) continue;

            for (int dir = 0; dir < 4; dir++) {
                bool win = true;
                for (int step = 1; step < 4; step++) {
                    int r = row + dr[dir] * step;
                    int c = col + dc[dir] * step;

                    if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] != player) {
                        win = false;
                        break;
                    }
                }
                if (win) return player;
            }
        }
    }
    return 0; // no winner yet
}

bool Board::isBoardFull() const {
    for (int col = 0; col < COLS; col++) {
        if (!isColumnFull(col)) return false;
    }
    return true;
}