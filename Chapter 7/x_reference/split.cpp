#include <vector>
#include <string>
#include <algorithm>
#include "split.h"

using namespace std;

bool not_space(char c)
{
	return !isspace(c);
}
bool space(char c)
{
	return isspace(c);
}

vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;
	iter i = str.begin();
	while (i != str.end())
	{
		//Skipping starting spaces
		i = find_if(i, str.end(), not_space);
		
		//Finding space after word's end
		iter j = find_if(i, str.end(), space);
		
		//Fill vector with words
		if (i != str.end())
		ret.push_back(string(i, j));
		
		i = j;
	}
	return ret;
}

