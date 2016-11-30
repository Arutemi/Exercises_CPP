#pragma once
#include <string>
#include <algorithm>

bool not_space(char c)
{
	return !isspace(c);
}

bool space(char c)
{
	return isspace(c);
}


// Версия функции split оперрцющая итераторами и потому не зависящая от типа выходного контейнера 

template <class Out>
void split(const std::string& str, Out os)
{
	typedef std::string::const_iterator iter;
	
	iter i = str.begin();
	while (i != str.end())
	{
		//Skipping starting spaces
		i = std::find_if(i, str.end(), not_space);

		//Finding space after word's end
		iter j = std::find_if(i, str.end(), space);

		
		if (i != str.end())
			*os++ = std::string(i, j);
		i = j;
	}
}