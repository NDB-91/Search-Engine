#ifndef _ACCOUNT_FACTORY_H_
#define _ACCOUNT_FACTORY_H_

#include <memory>
#include <string>

#include "IAccount.h"
#include "../student/Student.h"
#include "../lecturer/Lecturer.h"

class AccountFactory {
public:
    static std::shared_ptr<IAccount> create(const Student& student, const std::string& password);
    static std::shared_ptr<IAccount> create(const Lecturer& lecturer, const std::string& password);
};

#endif