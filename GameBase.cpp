#include "GameBase.h"
#include "common.h"
//select the game with given commend line input
gameBase* gameBase::chooseGame(int argc, char* argv[]) {
	if (argc > WINPIECES+1 || argc <= GAME)
		return 0;
	gameBase* gb;
	if (strcmp(argv[GAME], "TicTacToe") == 0)
	{
		gb = new ticTacToe();
		return gb;
	}

	if (strcmp(argv[GAME], "Gomoku") == 0)
	{
		if (argc == GAME + 1) {
			gb = new gomoku(19,5);
			return gb;
		}
		else if (argc == BOARDSIZE + 1) {
			int boardsize = stoi(argv[BOARDSIZE]);
			if (boardsize < 3 || boardsize > 100) {
				cout << "Invalid board" << endl;
				return 0;
			}
			else if (boardsize == 3) {
				gb = new gomoku(3, 3);
				return gb;
			}
			else if (boardsize == 4) {
				gb = new gomoku(4, 4);
				return gb;
			}
			else {
				gb = new gomoku(boardsize, 5);
				return gb;
			}
		}
		else if (argc == WINPIECES + 1) {
			int boardsize = stoi(argv[BOARDSIZE]);
			int winpieces = stoi(argv[WINPIECES]);
			if (boardsize < 3 || boardsize > 100 || winpieces < 3 || winpieces > boardsize) {
				cout << "Invalid board" << endl;
				return 0;
			}
			else {
				gb = new gomoku(boardsize, winpieces);
				return gb;
			}
		}
	}

	return 0;
}
//pompt the use for the place of move
int gameBase::prompt(unsigned int& x, unsigned int& y)
{
	cout << "Enters x,y to place your move or types quit to exit this game." << endl;
	string input;
	getline(cin, input);
	if (!input.compare("quit")) {
		return PLAYER_QUIT;
	}

	bool validInput = false;
	for (unsigned int i = 0; i <= input.size(); i++)
	{
		if (input[i] == ',')
		{
			input[i] = ' ';
			validInput = true;
		}
	}

	istringstream iss(input);

	if (validInput)
	{
		//input has a comma but does not fit
		if (!(iss >> x >> y))
		{
			cout << "Invalid input! Please input again" << endl;
			return COULD_NOT_EXTRACT_DIMENSION;
		}
		// input is out of range
		else if (x <= 0 || x > width || y <= 0 || y > height)
		{
			cout << "Out of range input" << endl;
			return INVALID_INPUT;
		}
		// input is a taken move
		else if (gameBoard[y][x] != " ")
		{
			cout << "Entry is taken already!" << endl;
			return INVALID_INPUT;
		}
		return SUCCESS;

	}
	// if input is not seperated by a comma
	else
	{
		cout << "Please enter input in (x,y) format" << endl;
		return INVALID_INPUT;
	}
}
//main loop that keeps the game going until a draw, a win, or a quit happens
int gameBase::play()
{
	print();
	// keep prompting the user for next move until draw, done or quit
	while (!done() & !draw())
	{
		if (turn() == PLAYER_QUIT)
		{
			cout << "Player quit game!" << endl;
			cout << "Total moves: " << move << endl;
			return PLAYER_QUIT;
		}
	}
	// print the winner if done
	if (done())
	{
		cout << "Player " + winner + " won!" << endl;
		return SUCCESS;
	}

	//print total moves made if draw
	if (draw())
	{
		cout << "Sorry! No more move to win" << endl;
		cout << "Total moves: " << move << endl;
		return DRAW;
	}

	return SUCCESS;
}