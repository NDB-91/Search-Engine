#include <sstream>
#include <iostream>

#include "AuthWithFile.h"
#include "../department/Department.h"
#include "../university/University.h"

AuthWithFile::AuthWithFile(const std::string& studentFile, const std::string& lecturerFile) : _studentFile(studentFile), _lecturerFile(lecturerFile) {}

AuthWithFile::~AuthWithFile() {}

bool AuthWithFile::registerAccount(
    const std::string& role,
    const std::string& email,
    const std::string& name,
    const std::string& password,
    const std::string& university,
    const std::string& department
) {
    if (role == "student") {
        return registerStudent(email, name, University::fromString(university), password);
    } else if (role == "lecturer") {
        return registerLecturer(email, name, fromString(department),  University::fromString(university), password);
    }
    return false;
}


bool AuthWithFile::loginAccount(const std::string& role, const std::string& email, const std::string& password) {
    if (role == "student") {
        return loginStudent(email, password);
    } else if (role == "lecturer") {
        return loginLecturer(email, password);
    }
    return false;
}

bool AuthWithFile::registerStudent(const std::string& email, const std::string& name, const University::Name university, const std::string& password) {
    std::ifstream file(_studentFile);
    std::string line;
    std::string storedEmail;

    while (getline(file, line)) {
        std::istringstream iss(line);
        iss >> storedEmail;

        if (storedEmail == email) {
            return false;
        }
    }

    std::ofstream outFile(_studentFile, std::ios::app);
    if (outFile.is_open()) {
        outFile << email << " " << name << " " << University::toString(university) << " " << password << std::endl;
        return true;
    }

    return false;
}

bool AuthWithFile::registerLecturer(const std::string& email, const std::string& name, const Department department, const University::Name university, const std::string& password) {
    std::ifstream file(_lecturerFile);
    std::string line;
    std::string storedEmail;

    while (getline(file, line)) {
        std::istringstream iss(line);
        iss >> storedEmail;

        if (storedEmail == email) {
            return false;
        }
    }

    std::ofstream outFile(_lecturerFile, std::ios::app);
    if (outFile.is_open()) {
        outFile << email << " " << name << " " << toString(department) << " " << University::toString(university) << password << std::endl;
        return true;
    }
    return false;
}

bool AuthWithFile::loginStudent(const std::string& email, const std::string& password) {
    return validateLogin(email, password, false);
}

bool AuthWithFile::loginLecturer(const std::string& email, const std::string& password) {
    return validateLogin(email, password, true);
}

bool AuthWithFile::validateLogin(const std::string& email, const std::string& password, bool isLecturer) {
    std::ifstream file;
    std::string line;
    bool found = false;
    if (isLecturer) {
        file.open(_lecturerFile);
    } else {
        file.open(_studentFile);
    }
    if (file.is_open()) {
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string storedEmail, storedPassword, name, universityStr, departmentStr;
            University::Name university;
            Department department;

            if (isLecturer) {
                iss >> storedEmail >> name >> departmentStr >> universityStr >> storedPassword;
                department = fromString(departmentStr);
                university = University::fromString(universityStr);
            } else {
                iss >> storedEmail >> name >> universityStr >> storedPassword;
                university = University::fromString(universityStr);
            }

            if (storedEmail == email && storedPassword == password) {
                found = true;
                break;
            }
        }
        file.close();
    }
    return found;
}