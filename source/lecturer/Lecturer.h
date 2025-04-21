#ifndef _LECTURER_H_
#define _LECTURER_H_

#include <string>

#include "../university/Univeristy.h"
#include "../department/Department.h"

class Lecturer {
public:
    Lecturer(const std::string& email, const std::string& name, const Department& department, const University::Name& university);
    ~Lecturer();

    std::string email() const;
    std::string name() const;
    Department department() const;
    University::Name university() const;
private:
    std::string _email;
    std::string _name;
    Department _department;
    University::Name _university;
};

#endif