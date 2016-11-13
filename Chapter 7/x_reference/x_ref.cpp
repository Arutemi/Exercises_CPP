#include <map>
#include <string>
#include <vector>
#include "split.h"
#include "x_ref.h"

// увага. по умолчанию функция обработки слов - split
std::map < std::string, std::vector<int> > xref(std::istream& in, std::vector<std::string> find_words(const std::string&)) {

	std::string line;
	int line_number = 0;
	std::map <std::string, std::vector<int> > ret;

	// reading input one line at a time
	while (std::getline(in, line)) {
		++line_number;
		
		// calling function to process line (splitting line in words by default)
		std::vector<std::string> words = find_words(line);
		
		for (std::vector<std::string>::const_iterator it = words.begin(); it != words.end(); ++it) {
			// filling map with words and appropriate line numbers
			ret[*it].push_back(line_number);

		}
		
	}
	return ret;
}