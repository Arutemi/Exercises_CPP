#include <algorithm>
#include "Student_info.h"
//#include "stdafx.h"


using  std::vector; using std::istream; using std::find;


// предикат  сравнения имен студентов. сравнивает положение в алфавитном порядке
bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
	//Читаем и записываем имя и оценки за экзамены
	is >> s.name >> s.midterm >> s.final;
	//Читаем и записываем домашние задания
	read_hw(is, s.homework);
	return is;
}

istream& read_hw(istream& in, vector<double>& hw){
	if (in)
	{
		//Очищаем вектор homework от предыдущих значений
		hw.clear();
		// Читаем оценки за домашку
		double x;
		while (in >> x)
		  hw.push_back(x);
		//очищаем входной поток для приема данных следующего студента
		in.clear();
	}
	return in;
}

// функция проверяет выполнены ли все домашние задания, т.е. не равны ли оценки 0
bool did_all_hw(const Student_info& s)
{
	return ((std::find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

