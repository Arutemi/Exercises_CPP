#ifndef analysis_h
#define analysis_h
#include <vector>
#include "Student_info.h"
#include <string>
#include <iostream>
#include "grade.h"
void write_analysis(std::ostream&, const std::string&,
	double gradeScheme(const Student_info&),
	const std::vector<Student_info>&,
	const std::vector<Student_info>&);

/*double median_analysis(const std::vector<Student_info>&);



double average_analysis(const std::vector<Student_info>&);

double optimistic_median_analysis(const std::vector<Student_info>&);
*/
double doAnalysis(const std::vector<Student_info>&, double gradeScheme(const Student_info&));

#endif