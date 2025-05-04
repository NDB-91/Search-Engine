#ifndef _IUSER_H_
#define _IUSER_H_

#include <string>

enum class Role {
    Student,
    Lecturer,
    Administrator,
};

class IUser {
public:
    virtual ~IUser() = default;
    virtual std::string email() const = 0;
    virtual Role role() const = 0;
};

#endif