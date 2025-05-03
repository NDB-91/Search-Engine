#ifndef _STUDENT_MANAGER_H_
#define _STUDENT_MANAGER_H_

#include <fstream>
#include <vector>
#include <unordered_map>

#include "Student.h"
#include "../university/University.h"

#define STUDENTS "database/entity/students.txt"

class StudentManager {
public:
    static StudentManager& instance();

    void addStudent(const Student& student);
    std::string getStudentName(const std::string& email) const;
    Student& getStudent(const std::string& email);

    StudentManager(const StudentManager&) = delete;
    StudentManager& operator=(const StudentManager&) = delete;
private:
    StudentManager();
    void loadStudents();
    void saveStudent(const Student& student);

    std::unordered_map<std::string, Student> _students;
};

#endif
