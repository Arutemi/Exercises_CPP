#pragma once

// book's implementation of max function
template <class T> T max(const T& left, const T& right);
template <class T> 
T max(const T& left, const T& right)
{
	return left > right ? left : right;
};

// book's implementation of find function 
// ����� �������� ���������������� �������� ������ ��� ������.  �������� ����������� ��������� ��������� == � != , ���������� * , � ��������� ++ 
// ����� ��������� ���������� �������� ����������� (input iterators)

template <class In, class X> In find(In begin, In end, const X& x);
template <class In, class X> 
In find(In begin, In end, const X& x)
{
	while (begin != end && *begin != x)
		++begin;
	return begin;
};

// function copy
// ����� �������� ���������������� �������� ������ ��� ������.  �������� ������ ����� ��������� " *X = " � ������������ �������� ���������� ++  
// ��� �� �� ��������� ������� ��������� ��� ��������� ����������, ���� �� ���� ����������� ���������
// ����� ��������� ���������� ��������� ����������� (output iterators)

template <class In, class Out> Out copy(In begin, In end, Out dest);
template <class In, class Out>
Out copy(In begin, In end, Out dest)
{
	while (begin != end)
		*dest++ = *begin++;
	return dest
};

//  function replace
// �������� ���������������� ������� ��� ������ � ������. ���������������� �������� (forward iterator) �������� ���������� ��� �������, ��� � �������� ����������, ����� ����������� �� ������� ��������
// � �� �� ������������ ��������� ��������:
// *it  ��� ��� ������, ���� ��� ������
// ++it � it++ , �� �� --it � it--
// it == j � it != j , ��� it � j ������ ����
// it -> member

template <class Forward, class X> void replace(Forward beg, Forward end, const X& x, const X& y);
template <class Forward, class X>
void replace(Forward beg, Forward end, const X& x, const X& y)
{
	while (beg != end) {
		if (*beg == x)
			*beg = y;
		++beg;
	}
};

// function reverse
// ��������������� �������� (bidirectional itearator). ����� �� �� ��������, ��� � ���������������� ��������. ���� ��������� ���������� -- � ����- � ��������  
template <class Bi> void reverse(Bi begin, Bi end);
template <class Bi> void reverse(Bi begin, Bi end)
{
	while (begin != end) {
		--end;
		if (begin != end)
			swap(*begin++, *end);
	}
};

// function binary_search
// �������� ������������� ������� (random access iterator ) �������� �������� ������ ���������, � ��� �� ��������� ��������� �������������� ��������
// � ����������� � ������ �������
template <class Random, class X> bool binary_search(Random begin, Random end, const X& x);
template <class Random, class X>
bool binary_search(Random begin, Random end, const X& x)
{
	while (begin < end) {
		// ������� ������� �����
		Random mid = begin + (end - begin) / 2;
		// ������� � ����� �������� ��������� ��������� x
		if (x < *mid)
			end = mid;
		else if (*mid < x)
			begin = mid + 1;
		// ���� ������ ����, ������� ��� *mid == x
		else return true;
	}
	return false;
};

