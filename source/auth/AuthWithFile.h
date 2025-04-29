#ifndef _AUTHWITHFILE_H_
#define _AUTHWITHFILE_H_

#include <string>
#include <fstream>
#include "../student/Student.h"
#include "../lecturer/Lecturer.h"

class AuthWithFile {
    public:
        AuthWithFile(const std::string& studentFile, const std::string& lecturerFile);
        ~AuthWithFile();

        bool registerStudent(const std::string& email, const std::string& name, University::Name university, const std::string& password);
        bool registerLecturer(const std::string& email, const std::string& name, Department department, University::Name university, const std::string& password);
    
        bool loginStudent(const std::string& email, const std::string& password);
        bool loginLecturer(const std::string& email, const std::string& password);

        std::string getFile(){
            return _studentFile;
        }
    
    private:
        bool validateLogin(const std::string& email, const std::string& password, bool isLecturer);
    
        std::string _studentFile;
        std::string _lecturerFile;
};
    
#endif
