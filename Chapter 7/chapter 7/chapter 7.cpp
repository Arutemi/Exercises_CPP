// chapter 7.cpp: Знакомство с контейнером map
// считаем и выводим сколько раз каждое слово встречается во входном потоке
//
// Simple app that counts words in cin stream text

#include "stdafx.h"
#include <string>
#include <iostream>
#include <map>

int main()
{
	std::string s;
	std::map <std::string, int> counters;
	while (std::cin >> s)
	{
		++counters[s];
	}
	for (std::map <std::string, int>::const_iterator iter = counters.begin(); iter != counters.end(); ++iter) {
		std::cout << "Word " << iter->first << " appears " << iter->second << " time(s)" << std::endl;
	}
	system("pause");
    return 0;
}

