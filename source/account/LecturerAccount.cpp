#include "LecturerAccount.h"

LecturerAccount::LecturerAccount(Lecturer lecturer, std::string password)
    : _lecturer(std::move(lecturer)), _password(std::move(password)) {}

std::string LecturerAccount::email() const {
    return _lecturer.email();
}

Role LecturerAccount::role() const {
    return Role::Lecturer;
}

bool LecturerAccount::verifyPassword(const std::string& password) const {
    return _password == password;
}

std::string LecturerAccount::password() const {
    return _password;
}

const Lecturer& LecturerAccount::profile() const {
    return _lecturer;
}