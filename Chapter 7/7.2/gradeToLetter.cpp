#pragma once

#include "Student_info.h"
#include "grade.h"

char gradeToLetter(const Student_info& s, double grade_func(const Student_info&) = grade)
{
	double grd = grade_func(s);
	if (grd <= 100 && grd >= 90)
		return 'A';
	else
		if (grd >= 80 && grd <= 89.99)
			return 'B';
		else
			if (grd >= 70 && grd <= 79.99)
				return 'C';
			else
				if (grd >= 60 && grd <= 69.99)
					return 'D';
				else
					return 'F';
}