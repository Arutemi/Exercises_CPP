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
	cout << "Введите по очереди имя студента, оценки за экзамен" << endl <<
	       "в середине и конце семестра и оценки за домашнюю работу:" << endl;
	while (read(cin, record)){
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}
	// Раасортировываем студентов в веторе по алфавиту
	sort(students.begin(), students.end(), compare);

	//Выводим фамилии и оценки
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i )
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
    system("pause");
	return 0;
}
