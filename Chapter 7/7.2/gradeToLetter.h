#pragma once

#include "Student_info.h"
#include "gradeToLetter.h"

char gradeToLetter(const Student_info& s, double grade_func(const Student_info&));