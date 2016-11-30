// 6. Student_info_with_algorithms.cpp: определяет точку входа для консольного приложения.
//
//#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "grade.h"
#include "Student_info.h"
#include "analysis.h"
#include "custom_sort.h"

using std::string;	using std::vector;
using std::cin;		using std::cout;
using std::endl; using std::domain_error;




int main()
{
	vector<Student_info> did; vector<Student_info> didnt;
	Student_info student;
	int count = 0;
	//Читаем записи, сортируем прилежных и лодырей в разные векторы
	while (read(cin, student))
	{
		custom_sort(did, didnt, student, did_all_hw);
	//	if (did_all_hw(student))
	//		did.push_back(student);
	//	else
	//		didnt.push_back(student);
		//cout << student.name << " " << ++count << endl;
	}

	//Проверяем есть ли элементы в контейнерах
	if (did.empty())
	{
		cout << "Nobody did all homework. What a bunch of losers." << endl;
		return 1;
	}
	if (didnt.empty())
	{
		cout << "Everybody's a goody-two-shoes. All homework is done." << endl;
		return 1;
	}

	//Анализируем оценки
	// write_analysis(cout, "median", median_analysis, did, didnt);
	// write_analysis(cout, "average", average_analysis, did, didnt);
	// write_analysis(cout, "median of homeworks turned in", optimistic_median_analysis, did, didnt);

	write_analysis(cout, "median", grade_aux, did, didnt);
	write_analysis(cout, "average", average_grade, did, didnt);
	write_analysis(cout, "median of homeworks turned in", optimistic_median, did, didnt);
	system("pause");
    return 0;
}

