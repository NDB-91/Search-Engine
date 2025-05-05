#ifndef _IACCOUNT_H_
#define _IACCOUNT_H_

#include <memory>
#include <string>
#include "../IUser.h"

/**
 * @file IAccount.h
 * @brief Defines the IAccount interface for managing user accounts.
 */

/**
 * @class IAccount
 * @brief Interface for managing user accounts.
 * 
 * The IAccount interface extends the IUser interface and provides additional methods
 * for verifying and retrieving account passwords.
 */
class IAccount : public IUser {
public:
    /**
     * @brief Virtual destructor for the IAccount interface.
     */
    virtual ~IAccount() = default;

    /**
     * @brief Verifies if the provided password matches the account's password.
     * 
     * @param password The password to verify.
     * @return True if the password matches, false otherwise.
     */
    virtual bool verifyPassword(const std::string& password) const = 0;

    /**
     * @brief Retrieves the account's password.
     * 
     * @return The password as a string.
     */
    virtual std::string password() const = 0;
};

#endif