/////////////////////////////////////////////////////////////////////////////////////////
// ”пражнение 7.1 ќтсортировать данные по частоте вхождени€, начина€ с самых редких и вывести данные их на консоль
#include "word_count.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

bool compare(std::pair<std::string, int> a, std::pair<std::string, int> b)
{
	return a.second < b.second;
}

int main()

{	
	//populating map with data
	std::map<std::string, int> wordCount = word_count(std::cin);
	
	typedef std::map<std::string, int>::const_iterator iter;
	std::vector<std::pair<std::string, int> > sorted_vec;
	// copying from map to vector for sorting purpose
	for (iter i = wordCount.begin(); i != wordCount.end(); ++i) {
		sorted_vec.push_back(*i);
	}
	//sorting vector
	std::sort(sorted_vec.begin(), sorted_vec.end(), compare);

	// sorted output
	for (std::vector<std::pair<std::string, int> >::const_iterator it = sorted_vec.begin();
																	it != sorted_vec.end();
																	++it) {
		std::cout << it->first << " " << it->second << " time(s)" << std::endl;
	}
	system("pause");
	return 0;
}