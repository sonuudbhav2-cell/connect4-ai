#pragma once
#include "Board.h"

int minimax(Board board, int depth, bool isMaximizing);
int findBestMove(Board board, int depth, int player);