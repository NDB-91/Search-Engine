#include "Utils.h"
#include <iostream>
#include <regex>

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::string toString(const University::Name& university) {
    switch (university) {
        case University::Name::HCMUS:
            return "HCMUS";
        case University::Name::USSH:
            return "USSH";
        case University::Name::UIT:
            return "UIT";
        case University::Name::HCMUT:
            return "HCMUT";
        case University::Name::HCMUTE:
            return "HCMUTE";
        case University::Name::NEU:
            return "NEU";
        case University::Name::FTU:
            return "FTU";
        default:
            return "Unknown_University";
    }
}

std::string toString(const Department& department) {
    switch (department) {
        case Department::MATHEMATICS:
            return "Mathematics";
        case Department::PHYSICS:
            return "Physics";
        case Department::CHEMISTRY:
            return "Chemistry";
        case Department::BIOLOGY:
            return "Biology";
        case Department::INFORMATION_TECHNOLOGY:
            return "Information Technology";
        case Department::LINGUISTICS:
            return "Linguistics";
        case Department::MARKETING:
            return "Marketing";
        case Department::ECONOMICS:
            return "Economics";
        case Department::PHILOSOPHY:
            return "Philosophy";
        default:
            return "Unknown_Department";
    }
}

University::Name convertUniversityName(const std::string& name) {
    if (name == "HCMUS")
        return University::Name::HCMUS;
    if (name == "USSH")
        return University::Name::USSH;
    if (name == "UIT")
        return University::Name::UIT;
    if (name == "HCMUT")
        return University::Name::HCMUT;
    if (name == "HCMUTE") 
        return University::Name::HCMUTE;
    if (name == "NEU")
        return University::Name::NEU;
    if (name == "FTU") 
        return University::Name::FTU;
    return University::Name::Unknown;
}

Department convertDepartment(const std::string& department) {
    if (department == "Mathematics") 
        return Department::MATHEMATICS;
    if (department == "Physics") 
        return Department::PHYSICS;
    if (department == "Chemistry") 
        return Department::CHEMISTRY;
    if (department == "Biology") 
        return Department::BIOLOGY;
    if (department == "Information Technology") 
        return Department::INFORMATION_TECHNOLOGY;
    if (department == "Linguistics") 
        return Department::LINGUISTICS;
    if (department == "Marketing") 
        return Department::MARKETING;
    if (department == "Economics") 
        return Department::ECONOMICS;
    if (department == "Philosophy") 
        return Department::PHILOSOPHY;
    return Department::Unknown;
}

bool validateEmail(const std::string& email, const std::string& role) {
    std::string domain = (role == "student") ? "@student" : "@lecturer";
    std::regex pattern(R"(^[a-zA-Z0-9._%+-]+)" + domain + R"($)");
    if (!std::regex_match(email, pattern)) {
        throw std::invalid_argument("Email must be in the format user" + domain);
    }
    return true;
}

bool validatePassword(const std::string& password) {
    if (password.length() < 8 || password.length() > 20) {
        throw std::invalid_argument("Password must be between 8 and 20 characters.");
    }
    return true;
}

bool validateDepartment(const std::string& department) {
    Department dept = convertDepartment(department);
    if (dept == Department::Unknown) {
        throw std::invalid_argument("Invalid department: " + department);
    }
    return true;
}

bool validateUniversity(const std::string& university) {
    University::Name uni = convertUniversityName(university);
    if (uni == University::Name::Unknown) {
        throw std::invalid_argument("Invalid university: " + university);
    }
    return true;
}

int getValidatedChoice() {
    std::string input;
    std::getline(std::cin, input);
    
    if (input.empty() || input.find_first_not_of("0123456789") != std::string::npos) {
        throw std::invalid_argument("Choice must be a number between 1 and 4.");
    }
    int c = std::stoi(input);
    if (c < 1 || c > 4) {
        throw std::invalid_argument("Choice must be between 1 and 4.");
    }
    return c;
}
