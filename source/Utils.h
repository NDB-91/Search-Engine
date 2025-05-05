#ifndef _UTILS_H_
#define _UTILS_H_

#include <string>
#include <sstream>
#include <vector>

#include "university/University.h"
#include "department/Department.h"

/**
 * @brief Splits a string into a vector of substrings based on a delimiter.
 * @param str The string to split.
 * @param delimiter The character used as the delimiter.
 * @return A vector of substrings.
 */
std::vector<std::string> split(const std::string& str, char delimiter);

/**
 * @brief Converts a University::Name enum to its string representation.
 * @param university The University::Name enum value.
 * @return The string representation of the university name.
 */
std::string toString(const University::Name& university);

/**
 * @brief Converts a Department object to its string representation.
 * @param department The Department object.
 * @return The string representation of the department.
 */
std::string toString(const Department& department);

/**
 * @brief Converts a string to a University::Name enum value.
 * @param name The string representation of the university name.
 * @return The corresponding University::Name enum value.
 */
University::Name convertUniversityName(const std::string& name);

/**
 * @brief Converts a string to a Department object.
 * @param department The string representation of the department.
 * @return The corresponding Department object.
 */
Department convertDepartment(const std::string& department);

#endif