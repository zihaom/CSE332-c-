#include <iostream>
#include "common.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
//tells the user how to use the program if wrong commendline given
int usageMessage(char* inputFileName, char* info)
{
	cout << "Usage: " << inputFileName << " " << info << endl;
	return 	WRONG_COMMAND_LINE_ARGUMENTS;
}