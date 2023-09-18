#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <fstream>
using std::ifstream;
#include <list>
using std::list;
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
using std::pair;

class InputParser
{
public:
	InputParser(string);

	string getInputFileName() const;
	void setInputFileName(string);

	unsigned getNumOfWords() const;
	void setNumOfWords(const unsigned);

	unordered_map<string, unsigned> getWords() const;
	void setWords(unordered_map<string, unsigned>);

	void parseInput();
	//Adj. functions
	void addWords(const string str);


private:
	string inputFileName;
	unsigned numOfWords;
	unordered_map<string, unsigned> words;

};

#endif