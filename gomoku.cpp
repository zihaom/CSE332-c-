#include "GameBase.h"
//constructor
gomoku::gomoku(int boardsize, int winpiece)
{
	move = 0;
	whoTurn = 1;
	width = boardsize;
	height = width;
	winpieces = winpiece;
	longestPieceLength = 2;
	for (unsigned int r = 0; r <= width; r++)
	{
		vector<string> row;
		gameBoard.push_back(row);
		for (unsigned int c = 0; c <= width; c++)
		{
			gameBoard[r].push_back(" ");
		}
	}
}
// ostream << operator
ostream& operator<<(ostream& os, const gomoku& game)
{
	for (unsigned int r = game.width; r >= 1; r--)
	{
		//print row number
		os << setw(game.longestPieceLength + 1) << to_string(r);
		for (unsigned int c = 1; c <= game.width; c++)
		{
			os << setw(game.longestPieceLength + 1) << game.gameBoard[r][c];
		}
		os << endl;
	}

	//print column number 
	cout << setw(game.longestPieceLength + 1) << "X";
	for (unsigned int i = 1; i <= game.width; i++)
		os << setw(game.longestPieceLength + 1) << to_string(i);
	os << endl;
	return os;
}
//checkes if a side wins
bool gomoku::done()
{
	bool ret = true;
	for (unsigned int r = 1; r <= width; r++)
	{
		for (unsigned int c = 1; c <= width; c++)
		{
			//right horizontal
			if (c + winpieces-1 <= width)
			{	
				for (unsigned int i = 0; i < winpieces; ++i) {
					ret &= (gameBoard[r][c+i] == "B");
				}
				if (ret) {
					winner = "Black";
					return true;
				}
				ret = true;
				for (unsigned int i = 0; i < winpieces; ++i) {
					ret &= (gameBoard[r][c + i] == "W");
				}
				if (ret) {
					winner = "White";
					return true;
				}
				ret = true;
			}
			//left horizontal
			if (c >= winpieces)
			{
				for (unsigned int i = 0; i < winpieces; ++i) {
					ret &= (gameBoard[r][c - i] == "B");
				}
				if (ret) {
					winner = "Black";
					return true;
				}
				ret = true;
				for (unsigned int i = 0; i < winpieces; ++i) {
					ret &= (gameBoard[r][c - i] == "W");
				}
				if (ret) {
					winner = "White";
					return true;
				}
				ret = true;
			}

			//up vertical
			if (r + winpieces - 1 <= width)
			{
				for (unsigned int i = 0; i < winpieces; ++i) {
					ret &= (gameBoard[r+i][c] == "B");
				}
				if (ret) {
					winner = "Black";
					return true;
				}
				ret = true;
				for (unsigned int i = 0; i < winpieces; ++i) {
					ret &= (gameBoard[r+i][c] == "W");
				}
				if (ret) {
					winner = "White";
					return true;
				}
				ret = true;
			}

			//down vertical
			if (r >= winpieces)
			{
				for (unsigned int i = 0; i < winpieces; ++i) {
					ret &= (gameBoard[r-i][c] == "B");
				}
				if (ret) {
					winner = "Black";
					return true;
				}
				ret = true;
				for (unsigned int i = 0; i < winpieces; ++i) {
					ret &= (gameBoard[r-i][c] == "W");
				}
				if (ret) {
					winner = "White";
					return true;
				}
				ret = true;
			}

			//up right
			if (r + winpieces - 1 <= width && c + winpieces - 1 <= width)
			{
				for (unsigned int i = 0; i < winpieces; ++i) {
					ret &= (gameBoard[r + i][c+i] == "B");
				}
				if (ret) {
					winner = "Black";
					return true;
				}
				ret = true;
				for (unsigned int i = 0; i < winpieces; ++i) {
					ret &= (gameBoard[r + i][c+i] == "W");
				}
				if (ret) {
					winner = "White";
					return true;
				}
				ret = true;
			}

			//down right
			if (r >= winpieces  && c + winpieces - 1 <= width)
			{
				for (unsigned int i = 0; i < winpieces; ++i) {
					ret &= (gameBoard[r - i][c + i] == "B");
				}
				if (ret) {
					winner = "Black";
					return true;
				}
				ret = true;
				for (unsigned int i = 0; i < winpieces; ++i) {
					ret &= (gameBoard[r - i][c + i] == "W");
				}
				if (ret) {
					winner = "White";
					return true;
				}
				ret = true;
			}
		
			//up left
			if (r + winpieces - 1 <= width && c >= winpieces)
			{
				for (unsigned int i = 0; i < winpieces; ++i) {
					ret &= (gameBoard[r + i][c - i] == "B");
				}
				if (ret) {
					winner = "Black";
					return true;
				}
				ret = true;
				for (unsigned int i = 0; i < winpieces; ++i) {
					ret &= (gameBoard[r + i][c - i] == "W");
				}
				if (ret) {
					winner = "White";
					return true;
				}
				ret = true;
			}

			//down left
			if (r >= winpieces && c >= winpieces)
			{
				for (unsigned int i = 0; i < winpieces; ++i) {
					ret &= (gameBoard[r - i][c-i] == "B");
				}
				if (ret) {
					winner = "Black";
					return true;
				}
				ret = true;
				for (unsigned int i = 0; i < winpieces; ++i) {
					ret &= (gameBoard[r - i][c-i] == "W");
				}
				if (ret) {
					winner = "White";
					return true;
				}
				ret = true;
			}
		}
	}
	
	return false;
}
//checks if it is a draw by checking any player is still able to win
bool gomoku::draw()
{
	vector< vector<string> > temp = gameBoard;
	//fill all empty entry with W and check for win
	for (unsigned int r = 0; r <= width; r++)
	{
		for (unsigned int c = 0; c <= width; c++)
		{
			if (gameBoard[r][c] == " ")
				gameBoard[r][c] =  "W";
		}
	}
	//if done then it is not draw yet, more move can still give the winner
	if (done()){
		gameBoard = temp;
		return false;
	}

	//fill all empty entry with B and check for win
	gameBoard = temp;
	for (unsigned int r = 0; r <= width; r++)
	{
		for (unsigned int c = 0; c <= width; c++)
		{
			if (gameBoard[r][c] == " ")
				gameBoard[r][c] = "B";
		}
	}
	//if done then it is not draw yet 
	if (done()) {
		gameBoard = temp;
		return false;
	}
	gameBoard = temp;
	return true;
}
//a turn function that pompts the player for the next move
int gomoku::turn()
{
	unsigned int xIn;
	unsigned int yIn;
	if (whoTurn == 1)
		cout << "Black Turn" << endl;
	else cout << "White Turn" << endl;

	int status = prompt(xIn, yIn);
	// if the input is valid
	if (status == SUCCESS)
	{
		move++;
		// check whose turn it is and place the move accordingly
		if (whoTurn == 1)
		{
			gameBoard[yIn][xIn] = "B";
			cout << *this << endl << endl;
			xMove.push_back("(" + to_string(xIn) + "," + to_string(yIn) + "); ");
			whoTurn = 0;
		}

		else
		{
			gameBoard[yIn][xIn] = "W";
			cout << *this << endl << endl;
			oMove.push_back("(" + to_string(xIn) + "," + to_string(yIn) + "); ");
			whoTurn = 1;
		}
		// print out all valid moves that have been made
		cout << "Player Black: ";
		for (string m : xMove)
			cout << m;
		cout << endl;
		cout << "Player White: ";
		for (string m : oMove)
			cout << m;
		cout << endl << endl;
		return SUCCESS;
	}

	else if (status == PLAYER_QUIT)
		return PLAYER_QUIT;

	else return turn();
}