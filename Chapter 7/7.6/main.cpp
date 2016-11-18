///////////////////////////////////////////////////////////////////////////
// Задача 7.6
// Написать программу для генерации рпедложений используя два
// вектора - один для сгенерированного предложения, другой в качестве стека
// типа FI-LO . Не использовать рекурсивных вызовов.
// Sentence_gen.cpp: определяет точку входа для консольного приложения.
//


#include <string>
#include <vector>
#include <iostream>
#include "gen_sentence.h"
#include <cstdlib>
#include <ctime>

using std::vector; using std::string;


int main()
{
	srand(time(NULL));
	// Загружаем грамматику
	std::cout << " Enta ur rulezz " << std::endl << std::endl;
	Grammar grmmr = read_grammar(std::cin);
	std::cin.clear();
	while (true) {
	// Генерируем предложение
	vector<string> sentence = gen_sentence(grmmr);
	// Выводим первое слово
	vector<string>::const_iterator it = sentence.begin();
	if (!sentence.empty()) {
		std::cout << *it;
		++it;
	}
	else
		return 1;
	// Выводим остальные слова, добавляя пробелы
	while (it != sentence.end()) {
		std::cout << " " << *it;
		++it;
	}
	std::cout << std::endl;
	std::cout << "Would you like to try again?";
	char n;
	std::cin >> n;
	if (n == 'n')
        return 0;
    //else
    //    system("pause");
	}
	system("pause");
	return 0;
}

