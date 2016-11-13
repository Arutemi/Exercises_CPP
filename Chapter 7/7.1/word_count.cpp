#include <string>
#include <map>
#include <iostream>
#include "word_count.h"


std::map<std::string, int> word_count(std::istream& in)
{

	std::string s;
	std::map <std::string, int> counters;
	while (in >> s)
	{
		++counters[s];
	}
	return counters;
}