#include <iostream>
#include <vector>
#include <string>
#include "split.h"


using namespace std;

int main()
{
    string s = "Little white rabbit hopping happily on grassy meadow in the middle of the night 324234 vdfv453";
    vector<string> res = split(s);
    for (int i = 0; i != res.size(); ++i)
    {
        cout << res[i] << endl;
    }
    return 0;
}
