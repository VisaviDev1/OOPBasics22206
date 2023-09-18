#ifndef OUTPUTHANDLER_H
#define OUTPUTHANDLER_H

#include <algorithm>
using std::sort;
#include <fstream>
using std::ofstream;
#include <iomanip>
using std::setprecision;
using std::fixed;
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;
using std::pair;
#include <vector>
using std::vector;

class OutputHandler
{
public:
	OutputHandler(string);

	string getOutputFileName() const;
	void setOutputFileName(string);

	void CSVOutput(const unordered_map<string, unsigned>, const unsigned) const;
private:
	string outputFileName;

};

#endif