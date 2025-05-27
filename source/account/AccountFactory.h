#ifndef _ACCOUNT_FACTORY_H_
#define _ACCOUNT_FACTORY_H_

#include <memory>
#include <string>

#include "../Object.h"
#include "IAccount.h"
#include "../student/Student.h"
#include "../lecturer/Lecturer.h"

/**
 * @file AccountFactory.h
 * @brief Defines the AccountFactory class for creating account objects.
 */

/**
 * @class AccountFactory
 * @brief Factory class for creating account objects.
 * 
 * The AccountFactory class provides static methods to create account objects
 * for students and lecturers with the specified details.
 */
class AccountFactory : public Object {
public:
    /**
     * @brief Creates an account for a student.
     * 
     * @param student The Student object containing student details.
     * @param password The password for the student account.
     * @return A shared pointer to the created IAccount object.
     */
    static std::shared_ptr<IAccount> create(const Student& student, const std::string& password);

    /**
     * @brief Creates an account for a lecturer.
     * 
     * @param lecturer The Lecturer object containing lecturer details.
     * @param password The password for the lecturer account.
     * @return A shared pointer to the created IAccount object.
     */
    static std::shared_ptr<IAccount> create(const Lecturer& lecturer, const std::string& password);
};

#endif