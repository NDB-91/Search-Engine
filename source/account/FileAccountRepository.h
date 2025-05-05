#ifndef _FILE_ACCOUNT_REPOSITORY_H_
#define _FILE_ACCOUNT_REPOSITORY_H_

#include <fstream>
#include <optional>
#include <vector>
#include <memory>
#include <string>

#include "IAccountRepository.h"

/**
 * @file FileAccountRepository.h
 * @brief Defines the FileAccountRepository class for managing accounts stored in a file.
 */

/**
 * @class FileAccountRepository
 * @brief Implements the IAccountRepository interface to manage accounts stored in a file.
 * 
 * The FileAccountRepository class provides methods to add accounts, find accounts by email,
 * and retrieve all accounts. It loads and saves account data to a specified file.
 */
class FileAccountRepository : public IAccountRepository {
public:
    /**
     * @brief Constructs a FileAccountRepository object.
     * 
     * @param filename The name of the file where account data is stored.
     */
    FileAccountRepository(const std::string& filename);

    /**
     * @brief Adds a new account to the repository.
     * 
     * @param account A shared pointer to the account to be added.
     */
    void add(std::shared_ptr<IAccount> account) override;

    /**
     * @brief Finds an account by email.
     * 
     * @param email The email address of the account to find.
     * @return An optional containing a shared pointer to the account if found, or an empty optional if not found.
     */
    std::optional<std::shared_ptr<IAccount>> findByEmail(const std::string& email) const override;

    /**
     * @brief Retrieves all accounts in the repository.
     * 
     * @return A vector of shared pointers to all accounts.
     */
    std::vector<std::shared_ptr<IAccount>> getAll() const override;

private:
    /**
     * @brief Loads accounts from the file into memory.
     */
    void loadAccounts();

    std::string _filename; /**< The name of the file where account data is stored. */
    std::vector<std::shared_ptr<IAccount>> _accounts; /**< The collection of accounts loaded from the file. */
};

#endif