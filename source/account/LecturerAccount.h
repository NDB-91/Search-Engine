#ifndef _LECTURER_ACCOUNT_H_
#define _LECTURER_ACCOUNT_H_

#include "IAccount.h"
#include "../lecturer/Lecturer.h"

class LecturerAccount : public IAccount {
public:
    LecturerAccount(Lecturer Lecturer, std::string password);

    std::string email() const override;
    Role role() const override;
    bool verifyPassword(const std::string& password) const override;
    std::string password() const override;

    const Lecturer& profile() const;
private:
    Lecturer _lecturer;
    std::string _password;
};

#endif