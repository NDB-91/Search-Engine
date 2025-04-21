#ifndef _MEMBER_H_
#define _MEMBER_H_

#include <iostream>
#include <string>

class Member {
public:
    std::string name;
    std::string role;

    Member() = default;
    Member(std::string mid1, std::string name1, std::string email1, std::string role1);

    std::string getEmail() const;
    void setEmail(const std::string& email1);

    void printDetails();

    friend class University;

private:
    std::string _memberID;
    std::string _email;

};
  
#endif
