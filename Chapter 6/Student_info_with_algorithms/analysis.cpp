#include <algorithm>
#include <numeric>
#include <vector>
#include "Student_info.h"
#include "analysis.h"
#include "grade.h"
#include "Median.h"
#include <iterator>
//#include "stdafx.h"

using std::vector;		using std::back_inserter;
using std::transform;	using std::ostream;
using std::string;		using std::endl;

/*
double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), average_grade);
	return median(grades);
}

double optimistic_median_analysis(const vector<Student_info>& students) {

	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
	return median(grades);
}
*/
double doAnalysis (const vector<Student_info>& students, double gradeScheme(const Student_info&)) {

	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), gradeScheme);
	return median(grades);
}


//Generic function for analysis
void write_analysis(ostream& out, const string& name,
					double gradeScheme(const Student_info&),
					const vector<Student_info>& did,
					const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " <<  doAnalysis(did, gradeScheme) << " , median(didnt) = " << doAnalysis(didnt, gradeScheme) << endl;
}




