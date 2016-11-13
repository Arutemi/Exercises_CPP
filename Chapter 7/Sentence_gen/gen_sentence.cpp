#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "split.h"
#include <stdexcept>
#include "nrand.h"
#include "gen_sentence.h"


using std::string;	using std::vector; using std::map;

#define START_RULE "<sentence>"

//Считывем грамматику из входного потока
Grammar read_grammar(std::istream& in) {
	Grammar ret;
	string line;

	// считываем входные данные
	while (std::getline(in, line)) {
		// разбиваем считанную строку на слова
		vector<string> entry = split(line);

		if (!entry.empty()) {
			//сохраняем правила в мэп Grammar
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
		}
	}
	return ret;
};

//Вспомогательная функция для старта с категории <предложение>
vector<string> gen_sentence(const Grammar& g) {

	vector<string> ret;
	gen_aux(g, START_RULE, ret);
	return ret;
};

bool bracketed(const string& s) {

	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
};

//функция замены по правилу использует рекурсивный вызов

void gen_aux(const Grammar& g, const string& word, vector<string>& ret) {
	// если слово не категория, пихаем его в выходной вектор
	if (!bracketed(word)) {
		ret.push_back(word);
	}
	else {
		//Ищем соответсвующее правило для значения word
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw std::logic_error("Пустое правило");
		//Считываем набор возможных правил
		const Rule_collection& c = it->second;

		//из которых случайно выбираем одно
		const Rule& r = c[nrand(c.size())];

		//Рекурсивно заменяем выбранное правило
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
			gen_aux(g, *i, ret);
	}
};

