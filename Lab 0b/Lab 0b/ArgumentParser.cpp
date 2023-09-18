#include "ArgumentParser.h"

ArgumentParser::ArgumentParser(int argc, char** argv)
	:numOfArguments(argc), arguments(argv)
{

}

int ArgumentParser::getNumOfArguments() const
{
	return numOfArguments;
}

void ArgumentParser::setNumOfArguments(int n)
{
	if (n >= 0) numOfArguments = n;
	else cout << "Error. Invalid number of arguments\n";
}

char** ArgumentParser::getArguments() const
{
	return arguments;
}

void ArgumentParser::setArguments(char** arg)
{
	arguments = arg;
}

bool ArgumentParser::argumentAnalyzer(string& input, string& output) const
{
	if (numOfArguments != 3)
	{
		cout << "Error. Invalid number of arguments." << endl;
		return false;
	}

	input = string(arguments[1]);
	output = string(arguments[2]);

	if (input.size() >= 5 && output.size() >= 5 &&
		input.substr(input.size() - 4) == ".txt" &&
		output.substr(output.size() - 4) == ".csv")
	{
		cout << input << ' ' << output;
		return true;
	}
	else
	{
		cout << "Error! Invalid arguments" << endl;
		return false;
	}

}