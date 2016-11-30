// Chapter 8.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include "Median.h"
#include <vector>
#include <iostream>
#include "Split_w_iters.h"
#include <iterator>


int main()
{
	//test of split func
	std::string try1 = "Assdf sdfksdf dsfe dfme dsf; w;efmd;f sdsadfsdsdgf dfgrgdfgdfsg";
	std::vector<std::string> vec;
	split(try1, back_inserter(vec));
	for (std::vector<std::string>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	
	// test of median func
	std::vector<double> testVec;
	for (double i = 1.0; i != 63.0; ++i) {
		testVec.push_back(i);
	}
	double res = median(testVec);
	std::cout << res << std::endl;
	system("pause");
    
	
	return 0;
}

