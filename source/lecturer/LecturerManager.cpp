#include "LecturerManager.h"
#include "../Utils.h"

#include <iostream>

LecturerManager& LecturerManager::instance() {
    static LecturerManager _instance;
    return _instance;
}

void LecturerManager::addLecturer(const Lecturer& lecturer) {
    saveLecturer(lecturer);
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

Lecturer& LecturerManager::getLecturer(const std::string& email) {
    return _lecturers[email];
}

LecturerManager::LecturerManager() {
    loadLecturers();
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
        Lecturer lecturer(email, name, dept, uni);
        _lecturers[email] = lecturer;
    }
    lecturersFile.close();
}

void LecturerManager::saveLecturer(const Lecturer& lecturer) {
    if(_lecturers.find(lecturer.email()) != _lecturers.end()) {
        return;
    }
    _lecturers[lecturer.email()] = lecturer;
    std::ofstream lecturersFile(LECTURERS, std::ios::app);
    if(!lecturersFile.is_open()) {
        throw std::runtime_error("Could not open lecturers file for writing");
        return;
    }
    lecturersFile << lecturer.email() << "|"
                    << lecturer.name() << "|"
                    << toString(lecturer.department()) << "|"
                    << toString(lecturer.university()) << "\n";
    lecturersFile.close();
}