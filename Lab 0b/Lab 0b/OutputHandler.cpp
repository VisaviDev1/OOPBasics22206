#include "OutputHandler.h"

OutputHandler::OutputHandler(string name)
	:outputFileName(name)
{

}

string OutputHandler::getOutputFileName() const
{
	return outputFileName;
}

void OutputHandler::setOutputFileName(string str)
{
	outputFileName = str;
}

bool comp(pair<string, unsigned>a, pair<string, unsigned>b)
{
	return a.second > b.second;
}

void OutputHandler::CSVOutput(const unordered_map<string, unsigned> words, const unsigned numOfWords) const
{
	ofstream out;

	out.open(outputFileName);

	if (out.is_open())
	{
		vector<pair<string, unsigned>> byFreq(words.begin(), words.end());
		sort(byFreq.begin(), byFreq.end(), comp);

		for (int i = 0; i < byFreq.size(); i++)
			out << byFreq[i].first << ',' << byFreq[i].second << ',' << fixed << setprecision(2) << (double)byFreq[i].second / ((double)numOfWords / 100) << "%\n";
	}
}