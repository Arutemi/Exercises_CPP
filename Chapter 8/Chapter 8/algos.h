#pragma once

// book's implementation of max function
template <class T> T max(const T& left, const T& right);
template <class T> 
T max(const T& left, const T& right)
{
	return left > right ? left : right;
};

// book's implementation of find function 
// «десь применен последовательный итератор только дл€ чтени€.  »тератор подерживает операторы сравнение == и != , дереференс * , и инкремент ++ 
// “акие итераторы называютс€ входными итераторами (input iterators)

template <class In, class X> In find(In begin, In end, const X& x);
template <class In, class X> 
In find(In begin, In end, const X& x)
{
	while (begin != end && *begin != x)
		++begin;
	return begin;
};

// function copy
// «десь применен последовательный итератор только дл€ записи.  »тератор должен уметь вычисл€ть " *X = " и поддреживать оператор инкремента ++  
// “ак же не позвол€ть двойной инкремент без опепраций присвоени€, дабы не было пропущенных элементов
// “акие итераторы называютс€ выходными итераторами (output iterators)

template <class In, class Out> Out copy(In begin, In end, Out dest);
template <class In, class Out>
Out copy(In begin, In end, Out dest)
{
	while (begin != end)
		*dest++ = *begin++;
	return dest
};

//  function replace
// »тератор последователного доступа дл€ чтени€ и записи. ќднонаправленный итератор (forward iterator) обладает свойствами как входных, так и выходных итераторов, кроме ограничени€ на двойную итерацию
// “ ак же поддерживает следующие операции:
// *it  как дл€ чтени€, таки дл€ записи
// ++it и it++ , но не --it и it--
// it == j и it != j , где it и j одного типа
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
// ƒвунаправленный итератор (bidirectional itearator). »меет те же свойства, что и однонаправленный итератор. ѕлюс операторы декремента -- в пост- и префиксе  
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
// »тератор произвольного доступа (random access iterator ) включает свойства других итерторов, а так же позвол€ет проводить арифметические операции
// с итераторами и целыми числами
template <class Random, class X> bool binary_search(Random begin, Random end, const X& x);
template <class Random, class X>
bool binary_search(Random begin, Random end, const X& x)
{
	while (begin < end) {
		// Ќаходим среднюю точку
		Random mid = begin + (end - begin) / 2;
		// находим в какой половине диапазона находитс€ x
		if (x < *mid)
			end = mid;
		else if (*mid < x)
			begin = mid + 1;
		// если попали сюда, логично что *mid == x
		else return true;
	}
	return false;
};

