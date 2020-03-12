#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "common.h"
using namespace std;

class gameBase {
protected:
	vector< vector<string> > gameBoard;			//2-d vector that represents the game board
	unsigned int move;							//the number of moves made
	unsigned int whoTurn;						//indicates whose turn
	vector<string> xMove;						//save O's past moves
	vector<string> oMove;						//save X's past moves
	string winner;								//show the winner
	unsigned int width;
	unsigned int height;
	unsigned int longestPieceLength;

public:
	static gameBase* chooseGame(int argc, char* argv[]);
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	int prompt(unsigned int& x, unsigned int& y);
	virtual int turn() = 0;
	int play();

};

class ticTacToe: public gameBase {
	public:
		ticTacToe();
		virtual void print() override {
			cout << *this << endl;
		};
		virtual bool done();
		virtual bool draw();
		virtual int turn();

		friend ostream& operator<<(ostream& stream, const ticTacToe& game);
};
ostream& operator<<(ostream& os, const ticTacToe& game);

class gomoku : public gameBase {
protected:
	unsigned int winpieces;

public:
	gomoku(int,int);
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	virtual void print() override {
		cout << *this << endl;
	};

	friend ostream& operator<<(ostream& stream, const gomoku& game);
};
ostream& operator<<(ostream& os, const gomoku& game);