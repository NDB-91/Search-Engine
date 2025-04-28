#ifndef _DEPARTMENT_H_
#define _DEPARTMENT_H_

#include <string>

enum class Department {
    MATHEMATICS,
    PHYSICS,
    CHEMISTRY,
    BIOLOGY,
    INFORMATION_TECHNOLOGY,
    LINGUISTICS,
    MARKETING,
    ECONOMICS,
    PHILOSOPHY,
    Unknown,
};

inline std::string toString(Department dept) {
    switch (dept) {
        case Department::MATHEMATICS: return "Mathematics";
        case Department::PHYSICS: return "Physics";
        case Department::CHEMISTRY: return "Chemistry";
        case Department::BIOLOGY: return "Biology";
        case Department::INFORMATION_TECHNOLOGY: return "Information_Technology";
        case Department::LINGUISTICS: return "Linguistics";
        case Department::MARKETING: return "Marketing";
        case Department::ECONOMICS: return "Economics";
        case Department::PHILOSOPHY: return "Philosophy";
        default: return "Unknown";
    }
}

inline Department fromString(const std::string& str) {
    if (str == "Mathematics") return Department::MATHEMATICS;
    if (str == "Physics") return Department::PHYSICS;
    if (str == "Chemistry") return Department::CHEMISTRY;
    if (str == "Biology") return Department::BIOLOGY;
    if (str == "Information_Technology") return Department::INFORMATION_TECHNOLOGY;
    if (str == "Linguistics") return Department::LINGUISTICS;
    if (str == "Marketing") return Department::MARKETING;
    if (str == "Economics") return Department::ECONOMICS;
    if (str == "Philosophy") return Department::PHILOSOPHY;
    return Department::Unknown;
}
#endif
