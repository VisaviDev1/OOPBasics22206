#include "InputParser.h"

InputParser::InputParser(string input)
{
	inputFileName = input;
}

string InputParser::getInputFileName() const
{
	return inputFileName;
}

void InputParser::setInputFileName(string str)
{
	inputFileName = str;
}

unsigned InputParser::getNumOfWords() const
{
	return numOfWords;
}

void InputParser::setNumOfWords(const unsigned n)
{
	numOfWords = n;
}

unordered_map<string, unsigned> InputParser::getWords() const
{
	return words;
}

void InputParser::setWords(unordered_map<string, unsigned> w)
{
	words = w;
}

void InputParser::parseInput()
{
	ifstream in;
	string line;

	in.open(inputFileName);

	if (in.is_open())
		while (getline(in, line))
		{
			addWords(line);
		}

	in.close();
}

void InputParser::addWords(const string str)
{
	string word;

	for (int i = 0; i <= str.size(); i++)
	{
		if ((str[i] >= '0' && str[i] <= '9') ||
			(str[i] >= 'a' && str[i] <= 'z') ||
			(str[i] >= 'A' && str[i] <= 'Z') ||
			(str[i] >= 'à' && str[i] <= 'ÿ') ||
			(str[i] >= 'À' && str[i] <= 'ß'))
		{
			word.push_back(str[i]);
		}
		else
		{
			if (word != "")
			{
				++words[word];
				numOfWords++;
			}
			word = "";
		}
	}
}
