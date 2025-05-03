#include "AccountService.h"
#include "../student/StudentManager.h"
#include "../lecturer/LecturerManager.h"

AccountService::AccountService(std::shared_ptr<IAccountRepository> repo)
    : _repo(repo) {}

void AccountService::registerStudent(const Student& student, const std::string& password) {
    if(_repo->findByEmail(student.email())){
        NotificationService::notify("Email already registered");
        return;
    }
    auto account = AccountFactory::create(student, password);
    _repo->add(account);
    StudentManager::instance().addStudent(student);
    NotificationService::notify("Registration successful");
}

void AccountService::registerLecturer(const Lecturer& lecturer, const std::string& password) {
    if(_repo->findByEmail(lecturer.email())){
        NotificationService::notify("Email already registered");
        return;
    }
    auto account = AccountFactory::create(lecturer, password);
    _repo->add(account);
    LecturerManager::instance().addLecturer(lecturer);
    NotificationService::notify("Registration successful");
}

bool AccountService::login(const std::string& email, const std::string& password) const {
    auto opt = _repo->findByEmail(email);
    if (!opt) {
        return false;
    }
    return (*opt)->verifyPassword(password);
}