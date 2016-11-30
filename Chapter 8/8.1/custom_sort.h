#pragma once
#include <vector>
#include "Student_info.h"

void custom_sort(std::vector<Student_info>&, std::vector<Student_info>&, const Student_info&, bool pred(const Student_info&));