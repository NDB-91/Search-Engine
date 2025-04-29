#ifndef _UTILS_H_
#define _UTILS_H_

#include <string>
#include <sstream>
#include <vector>

#include "university/University.h"
#include "department/Department.h"

std::vector<std::string> split(const std::string& str, char delimiter);
std::string toString(const University::Name& university);
std::string toString(const Department& department);
University::Name convertUniversityName(const std::string& name);
Department convertDepartment(const std::string& department);

#endif