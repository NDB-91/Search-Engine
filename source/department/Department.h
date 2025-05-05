#ifndef _DEPARTMENT_H_
#define _DEPARTMENT_H_

#include <string>

/**
 * @file Department.h
 * @brief Defines the Department enumeration for categorizing academic or organizational departments.
 */

/**
 * @enum Department
 * @brief Represents various departments in an organization or institution.
 * 
 * This enumeration is used to categorize entities into specific departments.
 */
enum class Department {
    MATHEMATICS,           /**< Represents the Mathematics department. */
    PHYSICS,               /**< Represents the Physics department. */
    CHEMISTRY,             /**< Represents the Chemistry department. */
    BIOLOGY,               /**< Represents the Biology department. */
    INFORMATION_TECHNOLOGY,/**< Represents the Information Technology department. */
    LINGUISTICS,           /**< Represents the Linguistics department. */
    MARKETING,             /**< Represents the Marketing department. */
    ECONOMICS,             /**< Represents the Economics department. */
    PHILOSOPHY,            /**< Represents the Philosophy department. */
    Unknown                /**< Represents an unknown or unspecified department. */
};

#endif
