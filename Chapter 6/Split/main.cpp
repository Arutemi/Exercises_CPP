#include <string>
#include <iostream>
#include <vector>
#include "split.h"

using namespace std;

int main()
{
	string str = "   Dat ass shakes like Mountain Fuji. Let's cut it in half.";
	cout << str << "\n\n";
	vector<string> vec = split(str);
	for (int i = 0; i != vec.size(); ++i)
	{
		cout << string(i, ' ') << vec[i] << endl;
	}
	return 0;
}