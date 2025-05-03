#ifndef _IACCOUNT_H_
#define _IACCOUNT_H_

#include <memory>

#include "../IUser.h"

class IAccount : public IUser {
public:
    virtual bool verifyPassword(const std::string& password) const = 0;
    virtual std::string password() const = 0;
};

#endif