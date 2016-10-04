#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include "split.h"

using namespace std;

bool not_space(const char& c)
{
    return !isspace(c);
}

bool space(const char& c)
{
    return isspace(c);
}


vector<string> split(const string& str)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter i = str.begin();
    while (i != str.end())
    {
        //Отсекаем начальные пробелы, если они есть
        i = find_if(i, str.end(), not_space);
        iter j = find_if(i, str.end(), space);
        ret.push_back(string(i, j));
        i = j;
    }

    return ret;
}
