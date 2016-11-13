#include "extract_fails.h"
#include <vector>
#include <list>
#include "Student_info.h"
#include "Group.h"
using namespace std;

Group extract_fails(Group& students)
{
	Group fail;
	Group::iterator iter = students.begin();
	while (iter != students.end())
	{
		if (fgrade(*iter))
		{
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			iter++;
	}
	return fail;
}


bool fgrade(const Student_info& s)
{
	return s.final_grade < 60;
}
  