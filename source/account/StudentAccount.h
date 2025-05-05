#ifndef _STUDENT_ACCOUNT_H_
#define _STUDENT_ACCOUNT_H_

#include "IAccount.h"
#include "../student/Student.h"

/**
 * @file StudentAccount.h
 * @brief Defines the StudentAccount class for managing student accounts.
 */

/**
 * @class StudentAccount
 * @brief Represents an account for a student.
 * 
 * The StudentAccount class implements the IAccount interface and provides
 * functionality for managing student-specific account details, such as
 * profile information and password verification.
 */
class StudentAccount : public IAccount {
public:
    /**
     * @brief Constructs a StudentAccount object.
     * 
     * @param student The Student object containing student details.
     * @param password The password for the student account.
     */
    StudentAccount(Student student, std::string password);

    /**
     * @brief Gets the email address of the student.
     * 
     * @return The email address as a string.
     */
    std::string email() const override;

    /**
     * @brief Gets the role of the student.
     * 
     * @return The role of the student as a `Role` enum.
     */
    Role role() const override;

    /**
     * @brief Verifies if the provided password matches the student's account password.
     * 
     * @param password The password to verify.
     * @return True if the password matches, false otherwise.
     */
    bool verifyPassword(const std::string& password) const override;

    /**
     * @brief Retrieves the password of the student's account.
     * 
     * @return The password as a string.
     */
    std::string password() const override;

    /**
     * @brief Gets the profile information of the student.
     * 
     * @return A constant reference to the Student object.
     */
    const Student& profile() const;

private:
    Student _student;       /**< The Student object containing student details. */
    std::string _password;  /**< The password for the student account. */
};

#endif