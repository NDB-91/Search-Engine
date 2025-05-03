#ifndef _LECTURER_MANAGER_H_
#define _LECTURER_MANAGER_H_

#include <fstream>
#include <string>
#include <unordered_map>

#include "Lecturer.h"
#include "../department/Department.h"
#include "../university/University.h"

#define LECTURERS "database/entity/lecturers.txt"

class LecturerManager {
public:
    static LecturerManager& instance();

    void addLecturer(const Lecturer& lecturer);
    std::string getLecturerName(const std::string& email) const;
    Lecturer& getLecturer(const std::string& email);

    LecturerManager(const LecturerManager&) = delete;
    LecturerManager& operator=(const LecturerManager&) = delete;
private:
    LecturerManager();
    void loadLecturers();
    void saveLecturer(const Lecturer& lecturer);

    std::unordered_map<std::string, Lecturer> _lecturers;
};

#endif