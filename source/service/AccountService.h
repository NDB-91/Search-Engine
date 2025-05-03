#ifndef _ACCOUNT_SERVICE_H_
#define _ACCOUNT_SERVICE_H_

#include "../account/IAccountRepository.h"
#include "../account/AccountFactory.h"
#include "NotificationService.h"

class AccountService {
public:
    AccountService(std::shared_ptr<IAccountRepository> repo);

    void registerStudent(const Student& student, const std::string& password);
    void registerLecturer(const Lecturer& lecturer, const std::string& password);
    bool login(const std::string& email, const std::string& password) const;
private:
    std::shared_ptr<IAccountRepository> _repo;
};

#endif