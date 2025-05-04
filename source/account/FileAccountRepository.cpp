#include "FileAccountRepository.h"
#include "AccountFactory.h"
#include "../IUser.h"
#include "../student/StudentManager.h"
#include "../lecturer/LecturerManager.h"
#include "../Utils.h"

#include <iostream>

FileAccountRepository::FileAccountRepository(const std::string& filename)
    : _filename(filename)
{
    loadAccounts();
}

void FileAccountRepository::add(std::shared_ptr<IAccount> account) {
    std::ofstream fileOut(_filename, std::ios::app);
    if(!fileOut.is_open()){
        throw std::runtime_error("Could not open file account");
        return;
    }
    fileOut << static_cast<int>(account->role()) << "|"
        << account->email() << "|"
        << account->password() << "\n";
    _accounts.emplace_back(account);
    fileOut.close();
}

std::optional<std::shared_ptr<IAccount>> FileAccountRepository::findByEmail(const std::string& email) const {
    for(const auto& account : _accounts) {
        if(email == account->email()){
            return account;
        }
    }
    return std::nullopt;
}

std::vector<std::shared_ptr<IAccount>> FileAccountRepository::getAll() const {
    return _accounts;
}

void FileAccountRepository::loadAccounts() {
    std::ifstream fileIn(_filename);
    if(!fileIn.is_open()){
        throw std::runtime_error("Could not open file account");
        return;
    }
    Role role;
    std::string email;
    std::string password;
    std::string line;
    while (getline(fileIn, line)) {
        auto tokens = split(line, '|');
        if (tokens.size() != 3) {
            throw std::runtime_error("Invalid account format");
        }
        int roleNumber = stoi(tokens[0]);
        role = static_cast<Role>(roleNumber);
        email = tokens[1];
        password = tokens[2];
        std::shared_ptr<IAccount> account;
        if (role == Role::Student) {
            Student student = StudentManager::instance().getStudent(email);
            account = AccountFactory::create(student, password);
        }
        else if (role == Role::Lecturer) {
            Lecturer lecturer = LecturerManager::instance().getLecturer(email);
            account = AccountFactory::create(lecturer, password);
        }
        else if (role == Role::Administrator) {

        }
        _accounts.emplace_back(account);
    }
    fileIn.close();
}