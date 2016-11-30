// ��������� ������� median ��������� ������� ��������� �������
// � ���������, ���������� ��������� ������� ������ �������� �� ���������� (���������� �� ����� ���������� ��� ���������� ��������� ������� ���� 
// ��� ������� � ������� �� main.cpp ���� ���������� - �.�. ���������� ����� � ��������� cpp-�����), ������� ���������� ���� ��������. 

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