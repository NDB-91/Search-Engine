#ifndef _FILE_ACCOUNT_REPOSITORY_H_
#define _FILE_ACCOUNT_REPOSITORY_H_

#include <fstream>

#include "IAccountRepository.h"

class FileAccountRepository : public IAccountRepository {
public:
    FileAccountRepository(const std::string& filename);
    
    void add(std::shared_ptr<IAccount> account) override;
    std::optional<std::shared_ptr<IAccount>> findByEmail(const std::string& email) const override;
    std::vector<std::shared_ptr<IAccount>> getAll() const override;
private:
    void loadAccounts();

    std::string _filename;
    std::vector<std::shared_ptr<IAccount>> _accounts;
};

#endif