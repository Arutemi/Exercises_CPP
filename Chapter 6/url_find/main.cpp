#include <string>
#include <iostream>
#include "url_find.h"

using namespace std;

int main()
{
	string str = "dfghdfh https://msdn.microsoft.com/en-us/library/d9x1s805.aspx  Edfhgfj h45f tfgdfg http://www.google.ru/ dfsh fghfdg gdfg http://en.cppreference.com/w/cpp/preprocessor/impl gdfgh";
	vector<string> vec = find_url(str);
	for (vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
	{
		cout << *i << endl;
	}

	return 0;
}