#ifndef analysis_h
#define analysis_h
#include <vector>
#include "Student_info.h"
#include <string>
#include <iostream>
#include "grade.h"



template <class Func> void write_analysis(std::ostream& out, const std::string& name,
	Func gradeScheme(const Student_info&),
	const std::vector<Student_info>& did,
	const std::vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << doAnalysis(did, gradeScheme) << " , median(didnt) = " << doAnalysis(didnt, gradeScheme) << std::endl;
}


/*double median_analysis(const std::vector<Student_info>&);



double average_analysis(const std::vector<Student_info>&);

double optimistic_median_analysis(const std::vector<Student_info>&);
*/


template <class Func> Func doAnalysis(const std::vector<Student_info>&, Func gradeScheme(const Student_info&));
template <class Func> Func doAnalysis(const vector<Student_info>& students, Func gradeScheme(const Student_info&)) {

	vector<Func> grades;
	transform(students.begin(), students.end(), back_inserter(grades), gradeScheme);
	return median(grades);
}

#endif