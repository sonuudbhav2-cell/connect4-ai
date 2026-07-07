#pragma once
#include <vector>

class Board {
public:
    static const int ROWS = 6;
    static const int COLS = 7;

    Board();

    bool dropPiece(int col, int player);
    bool isColumnFull(int col) const;
    bool isBoardFull() const;
    int checkWinner() const;
    void print() const;

private:
    std::vector<std::vector<int>> grid;
};