// Frame_with_iterators.cpp: определяет точку входа для консольного приложения.
//

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "frame.h"
#include "hcat.h"

using std::vector; using std::string; using std::endl; using std::cout;

void vec_print(vector<string>& vec) {
	for (vector<string>::const_iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << endl;
}

int main()
{
	vector<string> table;
	table.push_back("This is a greeting card.");
	table.push_back("This may seem strange,");
	table.push_back("but it is true.");
	table.push_back("Anyways. I happily greet you or whatever.");
	vector<string> framed = frame(table);
	vec_print(table);
	cout << endl << endl;
	vec_print(framed);
	cout << endl << endl;
	vec_print(hcat(framed, table));
	system("pause");
	return 0;
}

