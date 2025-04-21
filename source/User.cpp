#include "User.h"

User::User() : _isLoggedIn(false) {

}

User::~User() {

}

bool User::IsLoggedIn() const {
    return _isLoggedIn;
}

void User::login(const std::string& username, const std::string& password) {
    validateCredentials(username, password);
}

void User::logout() {
    _isLoggedIn = false;
    _currentUsername.clear();
}

void User::registerUser(const std::string& username, const std::string& password) {
    storeUserData(username, password);
}

void User::deleteUser(const std::string& username) {
    removeUserData(username);
}

void User::validateCredentials(const std::string& username, const std::string& password) {
    // Validate user credentials
    if (username == "admin" && password == "password") {
        _isLoggedIn = true;
        _currentUsername = username;
    } else {
        _isLoggedIn = false;
    }
}
void User::storeUserData(const std::string& username, const std::string& password) {
    // Store user data
    _currentUsername = username;
}
void User::removeUserData(const std::string& username) {
    // Remove user data
    if (_currentUsername == username) {
        _currentUsername.clear();
        _isLoggedIn = false;
    }
}