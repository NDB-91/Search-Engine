#ifndef _IAUTH_H_
#define _IAUTH_H_

#include <string>

class IAuth {
public:
    virtual bool registerAccount(
        const std::string& role, 
        const std::string& email, 
        const std::string& name, 
        const std::string& password, 
        const std::string& university, 
        const std::string& department = "") = 0;
    virtual bool loginAccount(
        const std::string& role, 
        const std::string& email, 
        const std::string& password) = 0;
    virtual ~IAuth() = default;
};

#endif
