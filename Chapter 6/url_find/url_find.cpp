#include <string>
#include <vector>
#include <algorithm>
#include "url_find.h"

using namespace std;


//предикат для функций url_beg и url_end
bool not_url_char(char c)
{
	//Символы, используемые в url адресах
	static string url_ch = "~;/?:@=&$-_.+!*'(),";
	//Определяем является ли символ частью url
	return !(isalnum(c) || (find(url_ch.begin(), url_ch.end(), c) != url_ch.end()));
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
	const string sep = "://";
	typedef string::const_iterator iter;
	iter i = b;
	//Ищем в последовательности [b,e) разделитель ://
	while ((i = search(i, e, sep.begin(), sep.end())) != e)
	{
		//Проверяем не находится ли разделитель в начале или конце строки
		if (i != b && i+sep.size() != e)
		{
			iter beg = i;
			//Посимвольно ищем начало имени протокола от сепаратора
			while (beg != b && isalpha(beg[-1]))
				--beg;
			// Проверяем есть ли хоть один символ до и после сепаратора
			if (beg != i && !not_url_char(i[sep.size()]))
				return beg;

		}
		// Найденный разделитель - пустышка, перешагнем через него и пойдем дальше
		i += sep.size();
	}
	// нихрена не нашли
	return e;

}


string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
	return find_if(b, e, not_url_char);
}

vector<string> find_url(const string& s)
{
	vector<string> urls;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();
	while (b != e)
	{
		b = url_beg(b, e);
		if (b != e)
		{
			iter after = url_end(b, e);
			urls.push_back(string(b, after));
			b = after;
		}

	}
	return urls;
}
