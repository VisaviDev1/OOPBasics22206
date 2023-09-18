#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

class ArgumentParser
{
public:
	ArgumentParser(int, char**);

	int getNumOfArguments() const;
	void setNumOfArguments(int);

	char** getArguments() const;
	void setArguments(char**);

	bool argumentAnalyzer(string&, string&) const;
private:
	int numOfArguments;
	char** arguments;
};

#endif