#include <stdexcept>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include "grade.h"
#include "Median.h"
#include "Student_info.h"
//#include "stdafx.h"

using std::domain_error;
using std::vector;

double grade_aux(const Student_info& s)
{
	try {
		return grade(s);
	}
	catch (domain_error) {
		return grade(s.midterm, s.final, 0);
	}
}

double grade(double midterm, double final, double homework){

	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw){

	if (hw.size() == 0)
	   throw domain_error("Студент не сделал ни одного домашнего задания!");
	return grade(midterm, final, median(hw));

}

double grade(const Student_info& s){

	return grade(s.midterm, s.final, s.homework);
}

double average_grade(const Student_info& s) {

	return grade(s.midterm, s.final, average(s.homework));
}

double average(const vector<double>& v)
{
	return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}


double optimistic_median(const Student_info& s) {

	vector<double> nonzero;
	std::remove_copy(s.homework.begin(), s.homework.end(), std::back_inserter(nonzero), 0);
	if (nonzero.empty())
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.final, median(nonzero));

}
