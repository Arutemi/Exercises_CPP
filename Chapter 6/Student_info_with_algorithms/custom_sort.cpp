#include <vector>
#include "Student_info.h"
#include "custom_sort.h"


using std::vector; using std::string;


void custom_sort(vector<Student_info>& vec1, vector<Student_info>& vec2, const Student_info& student, bool pred(const Student_info&)) {

	if (pred(student))
		vec1.push_back(student);
	else
		vec2.push_back(student);

	return;
}