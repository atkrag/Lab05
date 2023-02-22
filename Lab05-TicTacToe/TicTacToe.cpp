// preprocessor directives
#include <iostream>
#include "TicTacToe.h"

// constructor
TicTacToe::TicTacToe()
{
	resetBoard();
}

// resets the board to default configuration
void TicTacToe::resetBoard()
{
	for (int r = 0; r < NUMROWS; r++) // iterates through rows
	{
		for (int c = 0; c < NUMCOLUMNS; c++) // iterates through columns
		{
			board[r][c] = '*'; // assigns char '*' as empty space symbol
		}
	}
}

// places 'X' or 'O' at player-input location
void TicTacToe::playerTurn(char row, char column, char symbol)
{
	// update board
	board[row - 1][column - 1] = symbol;

}

// checks if user-input location is invalid (space already taken)
bool TicTacToe::checkTurnError(int row, int column)
{
	// defaults to true
	bool errorFound = true;

	if (board[row - 1][column - 1] == '*') // checks for blank space
	{
		errorFound = false;
	}

	return errorFound;
}

// checks if user-input location is invalid (out of bounds)
bool TicTacToe::checkTurnError(int num)
{
	// defaults to true
	bool errorFound = true;

	if ((num >= 1) || (num <= 4)) // checks for out of bounds
	{
		errorFound = false;
	}

	return errorFound;
}

// displays the board
void TicTacToe::displayBoard()
{
	for (int r = 0; r < NUMROWS; r++) // iterates through rows
	{
		for (int c = 0; c < NUMCOLUMNS; c++) // iterates through columns
		{
			std::cout << board[r][c] << " ";
		}
		std::cout << std::endl; // prints next row
	}
}

// checks if board is full
bool TicTacToe::spotsLeft()
{
	bool returnVar = false;

	for (int r = 0; r < NUMROWS; r++) // iterates through rows
	{
		for (int c = 0; c < NUMCOLUMNS; c++) // iterates through columns
		{
			if (board[r][c] == '*')
			{
				returnVar = true;
			}
		}
	}

	return returnVar; // default
}

// checks if a player has won
bool TicTacToe::playerWins(char symbol)
{
	bool win = (
		(board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol) // row 1
		||
		(board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol) // row 2
		||
		(board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol) // row 3
		||
		(board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol) // column 1
		||
		(board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol) // column 2
		||
		(board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol) // column 3
		||
		(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) // diagonal left to right
		||
		(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) // diagonal right to left
		);
	return win;
}

// checks if game over
bool TicTacToe::gameOver()
{
	return (playerWins('X') || playerWins('O') || !spotsLeft()); // 'X' wins OR 'O' wins OR board devoid of '*'
}

// displays winner or tie game
void TicTacToe::displayWinner()
{

	if (playerWins('X'))
	{
		std::cout << "Player X Wins!";
	}

	else if (playerWins('O'))
	{
		std::cout << "Player O Wins!";
	}

	else
	{
		std::cout << "The game ended in a tie!";
	}
}

// displays number of turns each player took
int TicTacToe::turns_taken()
{
	int numTurns = 0;

	for (int r = 0; r < NUMROWS; r++)
	{
		for (int c = 0; c < NUMCOLUMNS; c++)
		{
			if (board[r][c] == 'X' || board[r][c] == 'O')
			{
				numTurns++;
			}
		}
	}

	return numTurns;
}