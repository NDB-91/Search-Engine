#include "StudentManager.h"
#include "../Utils.h"

StudentManager& StudentManager::instance() {
    static StudentManager _instance;
    return _instance;
}

void StudentManager::addStudent(const Student& student) {
    saveStudent(student);
}

std::string StudentManager::getStudentName(const std::string& email) const {
    auto it = _students.find(email);
    if (it != _students.end()) {
        return it->second.name();
    }
    else {
        return "Student not found";
    }
}

Student& StudentManager::getStudent(const std::string& email) {
    return _students[email];
}

StudentManager::StudentManager() {
    loadStudents();
}

void StudentManager::loadStudents() {
    std::ifstream studentFile(STUDENTS);
    if (!studentFile.is_open()) {
        throw std::runtime_error("Could not open students file");
        return;
    }
    std::string email, name, university;
    std::string line;
    while (std::getline(studentFile, line)) {
        auto tokens = split(line, '|');
        if (tokens.size() != 3) {
            throw std::runtime_error("Invalid student format");
        }
        email = tokens[0];
        name = tokens[1];
        university = tokens[2];

        University::Name uni = convertUniversityName(university);
        Student student(email, name, uni);
        _students[email] = student;
    }
    studentFile.close();
}

void StudentManager::saveStudent(const Student& student) {
    if(_students.find(student.email()) != _students.end()) {
        return;
    }
    _students[student.email()] = student;
    std::ofstream studentFile(STUDENTS, std::ios::app);
    if (!studentFile.is_open()) {
        throw std::runtime_error("Could not open students file for writing");
        return;
    }
    studentFile << student.email() << "|"
                << student.name() << "|"
                << toString(student.university()) << "\n";
    studentFile.close();
}