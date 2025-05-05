#ifndef _IACCOUNT_REPOSITORY_H_
#define _IACCOUNT_REPOSITORY_H_

#include <memory>
#include <vector>
#include <optional>

#include "IAccount.h"

/**
 * @file IAccountRepository.h
 * @brief Defines the IAccountRepository interface for managing account storage and retrieval.
 */

/**
 * @class IAccountRepository
 * @brief Interface for managing account storage and retrieval.
 * 
 * The IAccountRepository interface provides methods to add accounts, find accounts by email,
 * and retrieve all accounts. Implementations of this interface can define specific storage mechanisms.
 */
class IAccountRepository {
public:
    /**
     * @brief Virtual destructor for the IAccountRepository interface.
     */
    virtual ~IAccountRepository() = default;

    /**
     * @brief Adds a new account to the repository.
     * 
     * @param account A shared pointer to the account to be added.
     */
    virtual void add(std::shared_ptr<IAccount> account) = 0;

    /**
     * @brief Finds an account by email.
     * 
     * @param email The email address of the account to be found.
     * @return An optional shared pointer to the account if found, otherwise std::nullopt.
     */
    virtual std::optional<std::shared_ptr<IAccount>> findByEmail(const std::string& email) const = 0;

    /**
     * @brief Retrieves all accounts in the repository.
     * 
     * @return A vector of shared pointers to all accounts in the repository.
     */
    virtual std::vector<std::shared_ptr<IAccount>> getAll() const = 0;
};

#endif