#include "Utils.h"

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

University::Name fromString(const std::string& str) {
    if (str == "HCMUS")
        return University::Name::HCMUS;
    if (str == "USSH")
        return University::Name::USSH;
    if (str == "UIT")
        return University::Name::UIT;
    if (str == "HCMUT")
        return University::Name::HCMUT;
    if (str == "HCMUTE") 
        return University::Name::HCMUTE;
    if (str == "NEU")
        return University::Name::NEU;
    if (str == "FTU") 
        return University::Name::FTU;
    return University::Name::Unknown;
}

Department fromStringtoDepartment(const std::string& str) {
    if (str == "Mathematics") 
        return Department::MATHEMATICS;
    if (str == "Physics") 
        return Department::PHYSICS;
    if (str == "Chemistry") 
        return Department::CHEMISTRY;
    if (str == "Biology") 
        return Department::BIOLOGY;
    if (str == "Information Technology") 
        return Department::INFORMATION_TECHNOLOGY;
    if (str == "Linguistics") 
        return Department::LINGUISTICS;
    if (str == "Marketing") 
        return Department::MARKETING;
    if (str == "Economics") 
        return Department::ECONOMICS;
    if (str == "Philosophy") 
        return Department::PHILOSOPHY;
    return Department::Unknown;
}