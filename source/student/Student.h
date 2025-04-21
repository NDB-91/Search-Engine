#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>

#include "../university/University.h"

class Student {
public:
    Student(const std::string& email, const std::string& name, const University::Name& university);
    ~Student();

    std::string email() const;
    std::string name() const;
    University::Name university() const;
private:
    std::string _email;
    std::string _name;
    University::Name _university;
};

#endif 