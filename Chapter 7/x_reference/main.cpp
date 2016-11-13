#include "x_ref.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>


int main() {

	std::map <std::string, std::vector<int> > database = xref(std::cin);
	typedef std::map <std::string, std::vector<int> >::const_iterator iter;

	for (iter it = database.begin(); it != database.end(); ++it) {
		std::cout << "Word \" " << it->first << " \" appears on line(s): " << it->second[0];
		
		for (std::vector<int>::const_iterator i = (it->second).begin() + 1; i != (it->second).end(); ++i) {
			std::cout << ", " << *i;
		}
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}