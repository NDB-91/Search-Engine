#ifndef _LECTURER_H_
#define _LECTURER_H_

#include <string>

#include "../university/University.h"
#include "../department/Department.h"

/**
 * @file Lecturer.h
 * @brief Defines the Lecturer class for representing lecturer information.
 */

/**
 * @class Lecturer
 * @brief Represents a lecturer in a university.
 * 
 * The Lecturer class provides methods to access lecturer details such as email, name,
 * department, and university affiliation.
 */
class Lecturer {
public:
    /**
     * @brief Default constructor for the Lecturer class.
     */
    Lecturer();

    /**
     * @brief Constructs a Lecturer object with specified details.
     * 
     * @param email The email address of the lecturer.
     * @param name The name of the lecturer.
     * @param department The department the lecturer belongs to.
     * @param university The university the lecturer is affiliated with.
     */
    Lecturer(const std::string& email, const std::string& name, const Department& department, const University::Name& university);

    /**
     * @brief Destructor for the Lecturer class.
     */
    ~Lecturer();

    /**
     * @brief Gets the email address of the lecturer.
     * @return The email address as a string.
     */
    std::string email() const;

    /**
     * @brief Gets the name of the lecturer.
     * @return The name as a string.
     */
    std::string name() const;

    /**
     * @brief Gets the department the lecturer belongs to.
     * @return The department as a Department enumeration value.
     */
    Department department() const;

    /**
     * @brief Gets the university the lecturer is affiliated with.
     * @return The university as a University::Name enumeration value.
     */
    University::Name university() const;

private:
    std::string _email;       /**< The email address of the lecturer. */
    std::string _name;        /**< The name of the lecturer. */
    Department _department;   /**< The department the lecturer belongs to. */
    University::Name _university; /**< The university the lecturer is affiliated with. */
};

#endif