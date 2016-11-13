#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ios>
#include <stdexcept>
#include <string>
#include <vector>
#include "Median.h"
#include "Student_info.h"
#include "grade.h"
#include <locale>
#include <map>
#include "gradeToLetter.h"

using std::vector; using std::cin;
using std::cout; using std::domain_error;
using std::endl; using std::max;
using std::setprecision; using std::sort;
using std::streamsize; using std::string;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0; // Длина самого длинного имени из введенных
								  //Заполняем вектор данными о студентах и вычисляем размер самого длинного имени
	cout << "Input student's data" << endl;
	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}
	// Рассортировываем студентов в векторе по алфавиту
	sort(students.begin(), students.end(), compare);

	
	//Выводим фамилии и оценки
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
	{
		//Форматированный вывод фамилии
		cout << students[i].name << string(maxlen - students[i].name.size() + 1, ' ');
		//Вывод оценки
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl; 	
	} 

	// creating map containing grades (letters) and associated students
	std::map<char, std::vector<Student_info> > letteredGrades;
	
	for (vector<Student_info>::const_iterator it = students.begin(); it != students.end(); ++it) {
		letteredGrades[gradeToLetter(*it, grade)].push_back(*it);
	}
	// output for map. student names sorted according to grade letter
	for (std::map<char, std::vector<Student_info> >::const_iterator iter = letteredGrades.begin(); iter != letteredGrades.end(); ++iter) {
		std::cout << iter->second.size() <<" grades of " << iter->first << ":";
		for (std::vector<Student_info>::const_iterator i = iter->second.begin(); i != iter->second.end(); ++i) {
			std::cout << " " <<  i->name;
		}
		std::cout << std::endl;
	}
	
	system("pause");
	return 0;
}
