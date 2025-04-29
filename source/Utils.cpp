#include "Utils.h"

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