// Ўаблонна€ функци€ median вычисл€ет медиану заданного вектора
//   сожалению, реализацию шаблонной функции нельз€ отдел€ть от объ€влени€ (компил€тор не может определить тип экземпл€ра шаблонной функции если 
// она попадет в отличый от main.cpp юнит трансл€ции - т.е. реализаци€ будет в отдельном cpp-файле), поэтому читаемость кода нарушена. 

//#pragma once
#ifndef GUARD_Median_h
#define GUARD_Median_h


#include <stdexcept>
#include <vector>
#include <algorithm>

template<class T> T median(std::vector<T>);

template<class T> T median(std::vector<T> v)
{
	typedef typename std::vector<T>::size_type vec_sz;
	vec_sz size = v.size();
	if (size == 0)
		throw std::domain_error("Can't compute median. Input vector is empty");
	std::sort(v.begin(), v.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];

};

#endif