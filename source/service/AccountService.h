#ifndef _ACCOUNT_SERVICE_H_
#define _ACCOUNT_SERVICE_H_

#include "../account/IAccountRepository.h"
#include "../account/AccountFactory.h"
#include "NotificationService.h"

/**
 * @file AccountService.h
 * @brief Defines the AccountService class for managing account-related operations.
 */

/**
 * @class AccountService
 * @brief Provides functionality for managing accounts, including registration and login.
 * 
 * The AccountService class allows for registering students and lecturers, as well as
 * handling login operations. It interacts with an account repository to manage account data.
 */
class AccountService {
public:
    /**
     * @brief Constructs an AccountService object.
     * 
     * @param repo A shared pointer to an IAccountRepository for managing account data.
     */
    AccountService(std::shared_ptr<IAccountRepository> repo);

    /**
     * @brief Registers a new student account.
     * 
     * @param student The Student object containing student details.
     * @param password The password for the student account.
     */
    void registerStudent(const Student& student, const std::string& password);

    /**
     * @brief Registers a new lecturer account.
     * 
     * @param lecturer The Lecturer object containing lecturer details.
     * @param password The password for the lecturer account.
     */
    void registerLecturer(const Lecturer& lecturer, const std::string& password);

    /**
     * @brief Logs in a user with the given email and password.
     * 
     * @param email The email address of the user.
     * @param password The password of the user.
     * @return True if the login is successful, false otherwise.
     */
    bool login(const std::string& email, const std::string& password) const;

private:
    std::shared_ptr<IAccountRepository> _repo; /**< The account repository for managing account data. */
};

#endif