#ifndef _STUDENT_ACCOUNT_H_
#define _STUDENT_ACCOUNT_H_

#include "IAccount.h"
#include "../student/Student.h"

class StudentAccount : public IAccount {
public:
    StudentAccount(Student student, std::string password);

    std::string email() const override;
    Role role() const override;
    bool verifyPassword(const std::string& password) const override;
    std::string password() const override;
    
    const Student& profile() const;
private:
    Student _student;
    std::string _password;
};

#endif