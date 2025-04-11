#include "user.h"

User::User() : isLoggedIn(false) {

}

User::~User() {

}

bool User::IsLoggedIn() const {
    return isLoggedIn;
}

void User::login(const std::string& username, const std::string& password) {
    validateCredentials(username, password);
}

void User::logout() {
    isLoggedIn = false;
    currentUsername.clear();
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
        isLoggedIn = true;
        currentUsername = username;
    } else {
        isLoggedIn = false;
    }
}
void User::storeUserData(const std::string& username, const std::string& password) {
    // Store user data
    currentUsername = username;
}
void User::removeUserData(const std::string& username) {
    // Remove user data
    if (currentUsername == username) {
        currentUsername.clear();
        isLoggedIn = false;
    }
}