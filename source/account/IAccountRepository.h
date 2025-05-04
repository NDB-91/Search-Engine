#ifndef _IACCOUNT_REPOSITORY_H_
#define _IACCOUNT_REPOSITORY_H_

#include <memory>
#include <vector>
#include <optional>

#include "IAccount.h"

class IAccountRepository {
public:
    virtual ~IAccountRepository() = default;
    virtual void add(std::shared_ptr<IAccount> account) = 0;
    virtual std::optional<std::shared_ptr<IAccount>> findByEmail(const std::string& email) const = 0;
    virtual std::vector<std::shared_ptr<IAccount>> getAll() const = 0;
};

#endif