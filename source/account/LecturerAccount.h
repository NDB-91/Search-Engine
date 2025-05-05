#ifndef _LECTURER_ACCOUNT_H_
#define _LECTURER_ACCOUNT_H_

#include "IAccount.h"
#include "../lecturer/Lecturer.h"

/**
 * @file LecturerAccount.h
 * @brief Defines the LecturerAccount class for managing lecturer accounts.
 */

/**
 * @class LecturerAccount
 * @brief Represents an account for a lecturer.
 * 
 * The LecturerAccount class implements the IAccount interface and provides
 * functionality for managing lecturer-specific account details, such as
 * profile information and password verification.
 */
class LecturerAccount : public IAccount {
public:
    /**
     * @brief Constructs a LecturerAccount object.
     * 
     * @param lecturer The Lecturer object containing lecturer details.
     * @param password The password for the lecturer account.
     */
    LecturerAccount(Lecturer lecturer, std::string password);

    /**
     * @brief Gets the email address of the lecturer.
     * 
     * @return The email address as a string.
     */
    std::string email() const override;

    /**
     * @brief Gets the role of the lecturer.
     * 
     * @return The role of the lecturer as a `Role` enum.
     */
    Role role() const override;

    /**
     * @brief Verifies if the provided password matches the lecturer's account password.
     * 
     * @param password The password to verify.
     * @return True if the password matches, false otherwise.
     */
    bool verifyPassword(const std::string& password) const override;

    /**
     * @brief Retrieves the password of the lecturer's account.
     * 
     * @return The password as a string.
     */
    std::string password() const override;

    /**
     * @brief Gets the profile information of the lecturer.
     * 
     * @return A constant reference to the Lecturer object.
     */
    const Lecturer& profile() const;

private:
    Lecturer _lecturer;       /**< The Lecturer object containing lecturer details. */
    std::string _password;    /**< The password for the lecturer account. */
};

#endif