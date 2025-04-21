#include "member.h"


Member::Member(std::string mid1, std::string name1, std::string email1, std::string role1) {
    _memberID = mid1;
    name = name1;
    _email = email1;
    role = role1;
}

std::string Member::getEmail() const {
    return _email;
}

void Member::setEmail(const std::string& email1) {
    _email = email1;
}

void Member::printDetails() {
    std::cout << "Member ID: " << _memberID << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Email: " << _email << "\n";
    std::cout << "Role: " << role << "\n";
}

