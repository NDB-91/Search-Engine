#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>

#include "../university/University.h"

/**
 * @file Student.h
 * @brief Defines the Student class for representing student information.
 */

/**
 * @class Student
 * @brief Represents a student in a university.
 * 
 * The Student class provides methods to access student details such as email, name,
 * and university affiliation.
 */
class Student {
public:
    /**
     * @brief Default constructor for the Student class.
     */
    Student();

    /**
     * @brief Constructs a Student object with specified details.
     * 
     * @param email The email address of the student.
     * @param name The name of the student.
     * @param university The university the student is affiliated with.
     */
    Student(const std::string& email, const std::string& name, const University::Name& university);

    /**
     * @brief Destructor for the Student class.
     */
    ~Student();

    /**
     * @brief Gets the email address of the student.
     * @return The email address as a string.
     */
    std::string email() const;

    /**
     * @brief Gets the name of the student.
     * @return The name as a string.
     */
    std::string name() const;

    /**
     * @brief Gets the university the student is affiliated with.
     * @return The university as a University::Name enumeration value.
     */
    University::Name university() const;

private:
    std::string _email;       /**< The email address of the student. */
    std::string _name;        /**< The name of the student. */
    University::Name _university; /**< The university the student is affiliated with. */
};

#endif