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
using std::getline;
using std::string;
#include <unordered_map>
using std::unordered_map;
using std::pair;
#include <vector>
using std::vector;

bool comp(pair<string, unsigned>, pair<string, unsigned>);
bool argumentAnalyzer(const int, const char**, string&, string&);
unordered_map<string, unsigned> inputAnalyzer(const string, unsigned&);
list<string> splitString(const string);
void CSVOutput(const string, const unordered_map<string, unsigned>, const unsigned);

int main(const int argc, const char **argv)
{
	string inputName,
		   outputName;
	unordered_map<string, unsigned> words;
	unsigned numOfWords = 0;

	if (argumentAnalyzer(argc, argv, inputName, outputName))
	{
		words = inputAnalyzer(inputName, numOfWords);
		CSVOutput(outputName, words, numOfWords);
	}

	return 0;
}

bool comp(pair<string, unsigned>a, pair<string, unsigned>b)
{
	return a.second > b.second;
}

bool argumentAnalyzer(const int argc, const char** argv, string& input, string& output)
{
	if (argc != 3)
	{
		cout << "Error. Invalid number of arguments." << endl;
		return false;
	}

	input = string(argv[1]);
	output = string(argv[2]);

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

unordered_map<string, unsigned> inputAnalyzer(const string input, unsigned& numOfWords)
{
	ifstream in;
	string line;
	list<string> lineWords;
	int numInLine;
	unordered_map<string, unsigned> words;

	in.open(input);

	if(in.is_open())
		while (getline(in, line))
		{
			lineWords = splitString(line);
			numInLine = lineWords.size();
			numOfWords += numInLine;
			for (int i = 0; i < numInLine; i++) 
			{
				if (lineWords.front() != "") ++words[lineWords.front()];
				lineWords.pop_front();
			}		
		}

	in.close();
	return words;
}

list<string> splitString(const string str)
{
	list<string> words;
	string word;
	unsigned wordSize = 0;
	for (int i = 0; i <= str.size(); i++) 
	{
		if ((str[i] >= '0' && str[i] <= '9') ||
			(str[i] >= 'a' && str[i] <= 'z') ||
			(str[i] >= 'A' && str[i] <= 'Z'))
		{
			word.push_back(str[i]);
		}
		else
		{
			words.push_back(word);
			word = "";
			wordSize = 0;
		}
	}

	return words;
}

void CSVOutput(const string output, unordered_map<string, unsigned> words, const unsigned numOfWords)
{
	ofstream out;
	
	out.open(output);

	if (out.is_open())
	{
		vector<pair<string, unsigned>> byFreq(words.begin(), words.end());
		sort(byFreq.begin(), byFreq.end(), comp);

		for (int i = 0; i < byFreq.size(); i++)
			out << byFreq[i].first << ',' << byFreq[i].second << ',' <<setprecision(2)<< (double)byFreq[i].second / ((double)numOfWords / 100) << "%\n";
	}
}