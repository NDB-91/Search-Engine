#include <sstream>
#include <iostream>

#include "AuthWithFile.h"
#include "../Utils.h"

AuthWithFile::AuthWithFile(const std::string& studentFile, const std::string& lecturerFile) : _studentFile(studentFile), _lecturerFile(lecturerFile) {}

AuthWithFile::~AuthWithFile() {}

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
        outFile << email << " " << name << " " << toString(university) << " " << password << std::endl;
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
        outFile << email << " " << name << " " << toString(department) << " " << toString(university) << " " << password << std::endl;
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
                department = convertDepartment(departmentStr);
                university = convertUniversityName(universityStr);
            } else {
                iss >> storedEmail >> name >> universityStr >> storedPassword;
                university = convertUniversityName(universityStr);
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