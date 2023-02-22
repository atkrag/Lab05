#pragma once
#include <iostream>

class TicTacToe
{
private:
	// variables for 3x3 tic tac toe grid
	const static int NUMROWS = 3; 
	const static int NUMCOLUMNS = 3;
	char board[NUMROWS][NUMCOLUMNS];

public:
	// initalizes gameboard to default state
	TicTacToe();

	// displays the board
	void displayBoard();

	// checks if board is full
	bool spotsLeft();

	// checks if a player has won
	bool playerWins(char symbol);

	// checks if game over
	bool gameOver();

	// displays winner or tie game
	void displayWinner();

	// displays number of turns each player took
	int turns_taken();

	// resets the board to default configuration
	void resetBoard();

	// checks if user-input location is invalid (space already taken)
	bool checkTurnError(int row, int column);

	// checks if user-input location is invalid (out of bounds)
	bool checkTurnError(int num);

	// places 'X' or 'O' at player-input location
	void playerTurn(char row, char column, char symbol);

};