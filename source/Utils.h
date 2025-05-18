#ifndef _UTILS_H_
#define _UTILS_H_

#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <stdexcept> 

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

/**
 * @brief Validates email format for student or lecturer roles.
 * @param email The email to validate.
 * @param role The role ("student" or "lecturer").
 * @return True if the email is valid, else throws an exception.
 */
bool validateEmail(const std::string& email, const std::string& role);

/**
 * @brief Validates password length (between 6 and 20 characters).
 * @param password The password to validate.
 * @return True if the password is valid, else throws an exception.
 */
bool validatePassword(const std::string& password);

/**
 * @brief Validates if the department exists in the list.
 * @param department The department name to validate.
 * @return True if the department exists, else throws an exception.
 */
bool validateDepartment(const std::string& department);

/**
 * @brief Validates if the university exists in the list.
 * @param university The university name to validate.
 * @return True if the university exists, else throws an exception.
 */
bool validateUniversity(const std::string& university);

/**
 * @brief Validates user choice input (must be a number between 1 and 4).
 * @return The valid choice number.
 * @throws std::invalid_argument If the choice is invalid.
 */
int getValidatedChoice();


#endif // _UTILS_H_
