#include "LecturerManager.h"
#include "../Utils.h"

LecturerManager& LecturerManager::instance() {
    static LecturerManager _instance;
    return _instance;
}

void LecturerManager::addLecturer(const std::string& email, const std::string& name, const Department& department, const University::Name& university) {
    Lecturer lecturer(email, name, department, university);
    _lecturers[email] = lecturer;
    saveLecturer(email, name, department, university);
}

std::string LecturerManager::getLecturerName(const std::string& email) const {
    auto it = _lecturers.find(email);
    if (it != _lecturers.end()) {
        return it->second.name();
    }
    else {
        return "Lecturer not found";
    }
}

void LecturerManager::loadLecturers() {
    std::ifstream lecturersFile(LECTURERS);
    if(!lecturersFile.is_open()) {
        throw std::runtime_error("Could not open lecturers file");
        return;
    }
    std::string email, name, department, university;
    std::string line;
    while (std::getline(lecturersFile, line)) {
        auto tokens = split(line, '|');
        if (tokens.size() != 4) {
            throw std::runtime_error("Invalid lecturer format");
        }
        email = tokens[0];
        name = tokens[1];
        department = tokens[2];
        university = tokens[3];

        Department dept = convertDepartment(department);
        University::Name uni = convertUniversityName(university);
        addLecturer(email, name, dept, uni);
    }
    lecturersFile.close();
}

void LecturerManager::saveLecturer(const std::string& email, const std::string& name, const Department& department, const University::Name& university) {
    if(_lecturers.find(email) != _lecturers.end()) {
        return;
    }
    std::ofstream lecturersFile(LECTURERS, std::ios::app);
    if(!lecturersFile.is_open()) {
        throw std::runtime_error("Could not open lecturers file for writing");
        return;
    }
    lecturersFile << email << "|" << name << "|" << toString(department) << "|" << toString(university) << "\n";
    lecturersFile.close();
}