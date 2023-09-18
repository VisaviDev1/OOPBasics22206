#include <algorithm>
using std::sort;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <iomanip>
using std::setprecision;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <list>
using std::list;
#include <string>
using std::string;

#include "ArgumentParser.h"
#include "InputParser.h"
#include "OutputHandler.h"

int main(int argc, char **argv)
{
	ArgumentParser argParser(argc, argv);
	string inputName,
		   outputName;
	unsigned numOfWords = 0;

	if (argParser.argumentAnalyzer(inputName, outputName))
	{
		InputParser inputParser(inputName);
		OutputHandler outputHandler(outputName);
		inputParser.parseInput();
		outputHandler.CSVOutput(inputParser.getWords(), inputParser.getNumOfWords());
	}

	return 0;
}
