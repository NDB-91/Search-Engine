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
            return "Unknown University";
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
        case Department::MAKETING:
            return "Marketing";
        case Department::ECONOMICS:
            return "Economics";
        case Department::PHILOSOPHY:
            return "Philosophy";
        default:
            return "Unknown Department";
    }
}