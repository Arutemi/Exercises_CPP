#include "Student_info.h"

using  std::vector; using std::istream;
// сравнение длины имен студентов
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
