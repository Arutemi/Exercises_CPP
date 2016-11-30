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


//Generic function for analysis





