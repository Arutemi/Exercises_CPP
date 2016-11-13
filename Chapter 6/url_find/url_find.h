#ifndef url_find_h
#define url_find_h

#include <string>
#include <vector>

bool not_url_char(char);

std::string::const_iterator url_beg(std::string::const_iterator, std::string::const_iterator);

std::string::const_iterator url_end(std::string::const_iterator, std::string::const_iterator);

std::vector<std::string> find_url(const std::string&);

#endif // !url_find_h