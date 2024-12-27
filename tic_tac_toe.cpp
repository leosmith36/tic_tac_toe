#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>

#include "tic_tac_toe.h"

Player board[3][3];

int main()
{
	Player currentPlayer = PLAYER_X;
	Player winner{};

	do {
		printBoard();
		collectInput(currentPlayer);

		// switch player
		currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
	} while (!(winner = checkWinner()));

	printBoard();
	printf("Player %c won!\n", winner);

	return 0;
}

// prints a horizontal divider for the  board
void printLine() {
	printf("+");
	for (int i = 0; i < 3; i++) {
		printf("---+");
	}
	printf("\n");
}

// prints the tic tac toe board
void printBoard() {
	printLine();

	for (int i = 0; i < 3; i++) {
		printf("|");
		for (int j = 0; j < 3; j++) {
			Player cur = board[i][j];
			Player entry = (cur == 0) ? ' ' : cur;
			printf(" %c |", entry);
		}
		printf("\n");
		printLine();
	}
}

// checks if a player has three in a row horizontally
Player checkHorizontals() {
	Player prev{};

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Player cur = board[i][j];
			if (!cur || (prev && cur != prev)) break;

			if (j == 2) return cur;

			prev = cur;
		}
	}

	return '\0';
}

// checks if a player has three in a row vertically
Player checkVerticals() {
	Player prev{};

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			Player cur = board[i][j];
			if (!cur || (prev && cur != prev)) break;

			if (i == 2) return cur;

			prev = cur;
		}
	}

	return '\0';
}

// checks if a player has three in a row diagonally
Player checkDiagonals() {
	Player prev{};

	for (int i = 0; i < 3; i++) {
		Player cur = board[i][i];
		if (!cur || (prev && cur != prev)) break;

		if (i == 2) return cur;

		prev = cur;
	}

	prev = 0;

	for (int i = 0; i < 3; i++) {
		Player cur = board[i][2 - i];
		if (!cur || (prev && cur != prev)) break;

		if (i == 2) return cur;

		prev = cur;
	}

	return '\0';
}

// checks if a player has three in a row
Player checkWinner() {
	Player winner{};

	if ((winner = checkHorizontals())) {
		return winner;
	}
	if ((winner = checkVerticals())) {
		return winner;
	}
	if ((winner = checkDiagonals())) {
		return winner;
	}

	return '\0';
}

// gets input from the player and adds to the board
void collectInput(Player p) {
	bool done = false;

	while (true) {
		printf("Player %c, enter a row and column:\n", p);

		std::string input{};
		std::getline(std::cin, input);

		if (input.size() != 2) {
			printf("Invalid input. Please try again.\n");
			continue;
		}

		int row = std::stoi(input.substr(0, 1));
		if (row < 1 || row > 3) {
			printf("Invalid row. Please try again.\n");
			continue;
		}

		int column = std::stoi(input.substr(1, 1));
		if (column < 1 || column > 3) {
			printf("Invalid column. Please try again.\n");
			continue;
		}

		if (board[row - 1][column - 1]) {
			printf("Row and column already taken. Please try again.\n");
			continue;
		}

		board[row - 1][column - 1] = p;

		return;
	}
}