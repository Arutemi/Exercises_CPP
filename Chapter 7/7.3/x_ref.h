#pragma once
#include <map>
#include <string>
#include <vector>
#include "split.h"
// увага. по умолчанию обработка слов - с помощью функции split
std::map < std::string, std::vector<int> > xref(std::istream&, std::vector<std::string> find_words(const std::string&) = split);