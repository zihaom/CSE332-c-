#pragma once
#include <vector>
#include <string>
using namespace std;

enum arrayIndices
{
	PROGRAM_NAME,
	GAME,
	BOARDSIZE,
	WINPIECES
};

enum programStatus
{
	SUCCESS,
	WRONG_COMMAND_LINE_ARGUMENTS,
	COULD_NOT_EXTRACT_DIMENSION,
	PLAYER_QUIT,
	INVALID_INPUT,
	DRAW
};

int usageMessage(char* inputFileName, char* info);