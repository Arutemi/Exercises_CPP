//This header defines type of container (vector or list) used for storing students' grades 
// comment/uncomment which one is needed 
#ifndef GUARD_Group_h
#define GUARD_Group_h

#include <vector>
#include <list>
#include "Student_info.h"

//typedef std::list<Student_info> Group;
typedef std::vector<Student_info> Group;

#endif