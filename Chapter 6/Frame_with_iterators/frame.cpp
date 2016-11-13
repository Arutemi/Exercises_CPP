#include <vector>
#include <string>
#include <algorithm>


using std::vector; using std::string;


vector<string>::size_type width(const vector<string>& v) {

	vector<string>::const_iterator iter;
	vector<string>::size_type maxlen = 0;
	for (iter = v.begin(); iter != v.end(); ++iter) {

		maxlen = std::max(maxlen, iter->size());
	}
	return maxlen;
}

vector<string> frame(const vector<string>& v) {

	vector<string> ret;
	int maxlen = width(v);
	string border = string(maxlen + 4, '*');
	string filler = "* " + string(maxlen, ' ') + " *";
	ret.push_back(border);
	ret.push_back(filler);
	vector<string>::const_iterator iter;

	for (iter = v.begin(); iter != v.end(); ++iter) {

		ret.push_back("* " + *iter + string(maxlen - iter->size(), ' ') + " *");
	}
	ret.push_back(filler);
	ret.push_back(border);
	return ret;
}