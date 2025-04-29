#ifndef _LECTURER_MANAGER_H_
#define _LECTURER_MANAGER_H_

#include <fstream>
#include <string>
#include <unordered_map>

#include "Lecturer.h"
#include "../department/Department.h"
#include "../university/University.h"

#define LECTURERS "lecturers.txt"

class LecturerManager {
public:
    static LecturerManager& instance();

    void addLecturer(const std::string& email, const std::string& name, const Department& department, const University::Name& university);
    std::string getLecturerName(const std::string& email) const;

    LecturerManager(const LecturerManager&) = delete;
    LecturerManager& operator=(const LecturerManager&) = delete;
private:
    LecturerManager() = default;
    void loadLecturers();
    void saveLecturer(const std::string& email, const std::string& name, const Department& department, const University::Name& university);

    std::unordered_map<std::string, Lecturer> _lecturers;
};

#endif