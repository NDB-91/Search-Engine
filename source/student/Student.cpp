#include "Student.h"

Student::Student()
    : _email(""), _name(""), _university(University::Name::Unknown) {}

Student::Student(const std::string& email, const std::string& name, const University::Name& university)
    : _email(email), _name(name), _university(university) {}

Student::~Student() {

}

std::string Student::email() const {
    return _email;
}

std::string Student::name() const {
    return _name;
}

University::Name Student::university() const {
    return _university;
}