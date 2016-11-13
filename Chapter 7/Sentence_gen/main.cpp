// Sentence_gen.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include "gen_sentence.h"
#include <cstdlib>
#include <ctime>

using std::vector; using std::string;


int main()
{
	srand(time(nullptr));
	std::cout << " Enta ur rulezz " << std::endl << std::endl;
	// Генерируем предложение
	vector<string> sentence = gen_sentence(read_grammar(std::cin));
	// Выводим первое слово
	vector<string>::const_iterator it = sentence.begin();
	if (!sentence.empty()) {
		std::cout << *it;
		++it;
	}
	// Выводим остальные слова, добавля пробелы
	while (it != sentence.end()) {
		std::cout << " " << *it;
		++it;
	}
	std::cout << std::endl;
	system("pause");
    return 0;
}

