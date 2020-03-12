#include <iostream>
#include "GameBase.h"
#include "common.h"

using namespace std;


int main(int argc, char* argv[])
{
	gameBase* gb;
	try {
		gb = gameBase::chooseGame(argc, argv);
	}
	catch (int BAD_ALLOC) {
		return BAD_ALLOC;
	}

	if (gb != 0) {
		shared_ptr<gameBase> ptr(gb);
		return gb->play();
	}
	else return usageMessage(argv[PROGRAM_NAME], "TicTacToe|Gomoku (<boardsize> <pieces to win>) \n");
}