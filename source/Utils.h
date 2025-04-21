#ifndef _UTILS_H_
#define _UTILS_H_

#include <string>

#include "university/University.h"
#include "department/Department.h"

std::string toString(const University::Name& university);
std::string toString(const Department& department);

#endif