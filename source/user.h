#ifndef _USER_H_
#define _USER_H_

#include <string>

class User {
public:
    User();
    ~User();

    bool IsLoggedIn() const;

    void login(const std::string& username, const std::string& password);
    void logout();
    void registerUser(const std::string& username, const std::string& password);
    void deleteUser(const std::string& username);

private:
    std::string _currentUsername;
    bool _isLoggedIn;

    void validateCredentials(const std::string& username, const std::string& password);
    void storeUserData(const std::string& username, const std::string& password);
    void removeUserData(const std::string& username);
};

#endif