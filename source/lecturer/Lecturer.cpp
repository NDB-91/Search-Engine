#include "Lecturer.h"

Lecturer::Lecturer(const std::string& email, const std::string& name, const Department& department, const University::Name& university)
    : _email(email), _name(name), _department(department), _university(university) {}

Lecturer::~Lecturer() {

}

std::string Lecturer::email() const {
    return _email;
}

std::string Lecturer::name() const {
    return _name;
}

Department Lecturer::department() const {
    return _department;
}

University::Name Lecturer::university() const {
    return _university;
}