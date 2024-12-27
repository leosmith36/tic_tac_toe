#pragma once

#include <iostream>

using Player = char;

constexpr Player PLAYER_X = 'X';
constexpr Player PLAYER_O = 'O';

using PlayerInput = struct {
	int row;
	int column;
};

void printBoard();
void printLine();
Player checkWinner();
Player checkHorizontals();
Player checkVerticals();
Player checkDiagonals();
void collectInput(Player);