#include "AccountFactory.h"
#include "StudentAccount.h"
#include "LecturerAccount.h"

std::shared_ptr<IAccount> AccountFactory::create(const Student& student, const std::string& password) {
    return std::make_shared<StudentAccount>(student, password);
}

std::shared_ptr<IAccount> AccountFactory::create(const Lecturer& lecturer, const std::string& password) {
    return std::make_shared<LecturerAccount>(lecturer, password);
}