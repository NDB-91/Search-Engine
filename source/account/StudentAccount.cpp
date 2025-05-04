#include "StudentAccount.h"

StudentAccount::StudentAccount(Student student, std::string password)
    : _student(std::move(student)), _password(std::move(password)) {}

std::string StudentAccount::email() const {
    return _student.email();
}

Role StudentAccount::role() const {
    return Role::Student;
}

bool StudentAccount::verifyPassword(const std::string& password) const {
    return _password == password;
}

std::string StudentAccount::password() const {
    return _password;
}

const Student& StudentAccount::profile() const {
    return _student;
}