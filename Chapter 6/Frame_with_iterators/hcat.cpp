#include <string>
#include <vector>
#include "frame.h"

using std::vector;  using std::string;

vector<string> hcat(const vector<string>& left, const vector<string>& right) {

	vector<string>::size_type l_width = width(left) + 1;
	vector<string>::const_iterator i = left.begin(), j = right.begin();
	vector<string> ret;
	while (i != left.end() || j != right.end()) {
		string temp;
		if (i != left.end()) {
			temp = *(i++);
		}
		temp += string(l_width - temp.size(), ' ');
		if (j != right.end()) {
			temp += *(j++);
		}
		ret.push_back(temp);
	}
	return ret;
}