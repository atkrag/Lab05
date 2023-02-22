#include <iostream>
#include "TicTacToe.h"

int main()
{
	// initialize game board array
	TicTacToe game;

	// variables for user input
	unsigned int row;
	unsigned int column;

	// play game
	while (!game.gameOver())
	{
		// player 1 turn
		game.displayBoard();
		std::cout << "Player X's Turn \n";

		// input for row
		while (std::cout << "Please enter a row: " && !(std::cin >> row) || game.checkTurnError(row))
		{
			std::cin.clear(); // clear bad input flag
			std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n'); // discard input
			std::cout << "Entry must be between 1 and 3 \n";
		}

		// input for column
		while (std::cout << "Please enter a column: " && !(std::cin >> column) || game.checkTurnError(column))
		{
			std::cin.clear(); // clear bad input flag
			std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n'); // discard input
			std::cout << "Entry must be between 1 and 3 \n";
		}

		// ensures input is not out of bounds
		while (game.checkTurnError(row, column))
		{
			std::cout << "Spot already taken, please try again: \n";
			// input for row
			while (std::cout << "Please enter a row: " && !(std::cin >> row) || game.checkTurnError(row))
			{
				std::cin.clear(); // clear bad input flag
				std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n'); // discard input
				std::cout << "Entry must be between 1 and 3 \n";
			}

			// input for column
			while (std::cout << "Please enter a column: " && !(std::cin >> column) || game.checkTurnError(column))
			{
				std::cin.clear(); // clear bad input flag
				std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n'); // discard input
				std::cout << "Entry must be between 1 and 3 \n";
			}
		}

		// assigns 'X' to input row and column on game board
		game.playerTurn(row, column, 'X');
		game.displayBoard();
		std::cout << std::endl;

		// player 2 turn
		if (!game.gameOver())
		{
			std::cout << "Player O's Turn \n";

			// input for row
			while (std::cout << "Please enter a row: " && !(std::cin >> row) || game.checkTurnError(row))
			{
				std::cin.clear(); // clear bad input flag
				std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n'); // discard input
				std::cout << "Entry must be between 1 and 3 \n";
			}

			// input for column
			while (std::cout << "Please enter a column: " && !(std::cin >> column) || game.checkTurnError(column))
			{
				std::cin.clear(); // clear bad input flag
				std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n'); // discard input
				std::cout << "Entry must be between 1 and 3 \n";
			}

			// ensures input is not out of bounds
			while (game.checkTurnError(row, column))
			{
				std::cout << "Spot already taken, please try again: \n";
				// input for row
				while (std::cout << "Please enter a row: " && !(std::cin >> row) || game.checkTurnError(row))
				{
					std::cin.clear(); // clear bad input flag
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n'); // discard input
					std::cout << "Entry must be between 1 and 3 \n";
				}

				// input for column
				while (std::cout << "Please enter a column: " && !(std::cin >> column) || game.checkTurnError(column))
				{
					std::cin.clear(); // clear bad input flag
					std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n'); // discard input
					std::cout << "Entry must be between 1 and 3 \n";
				}
			}

			// assigns 'X' to input row and column on game board
			game.playerTurn(row, column, 'O');
		}
	}

	// display winner
	std::cout << game.turns_taken() << " turns were played this round." << std::endl;
	game.displayWinner();
}