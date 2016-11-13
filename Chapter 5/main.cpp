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
#include "extract_fails.h"
#include <list>
#include "Group.h"
using std::vector; using std::cin;
using std::cout; using std::domain_error;
using std::endl; using std::max;
using std::setprecision; using std::sort;
using std::streamsize; using std::string;
using std::list;
 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
	Group students;
	Student_info record;
	string::size_type maxlen = 0; // will store longest name size
	cout << "Please, input data for all students in following order:" << endl <<
	       "Name: \n"
	       "Midterm exam: \n"
	       "Final exam: \n"
	       "Homework grades: " << endl << "End your input with EOF Marker (Ctrl + z)" << endl;
	int count = 0;
	while (read(cin, record)){
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
		cout << record.name << " " << ++count << endl;
	}
	//Compute final grade and save it in struct
	for (Group::iterator iter = students.begin(); iter != students.end(); ++iter)
	{
		(*iter).final_grade = grade(*iter);
	}
	//Sorting is disabled for compatibility
	//if (isList)
	//{
	//	students.sort(compare);
	//	//fails.sort(compare);
	//}
	//else
	//{
	//	sort(students.begin(), students.end(), compare);
	//	//sort(fails.begin(), fails.end(), compare);
	//}
	
	Group fails = extract_fails(students);
	//output
	cout << "These students have passed: " << endl;
	for (Group::const_iterator iter = students.begin(); iter != students.end(); ++iter )
	{
		//��������������� ����� �������
		cout << iter -> name << string(maxlen - (*iter).name.size() + 1, ' ');
		//����� ������
		try {
			streamsize prec = cout.precision();
			cout << setprecision(3) << iter -> final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
   
   	cout << endl << "And these students have failed: " << endl;
   	for (Group::const_iterator iter = fails.begin(); iter != fails.end(); ++iter )
	{
		//��������������� ����� �������
		cout << iter -> name << string(maxlen - (*iter).name.size() + 1, ' ');
		//����� ������
		try {
			streamsize prec = cout.precision();
			cout << setprecision(3) << iter -> final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
      system("pause");
	return 0;
}
