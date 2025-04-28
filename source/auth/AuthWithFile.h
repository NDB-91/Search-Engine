#ifndef _AUTHWITHFILE_H_
#define _AUTHWITHFILE_H_

#include <string>
#include <fstream>
#include "Student.h"
#include "Lecturer.h"
#include "IAuth.h"  // Include IAuth interface

class AuthWithFile : public IAuth {
    public:
        AuthWithFile(const std::string& studentFile, const std::string& lecturerFile);
    
        bool registerAccount(const std::string& role, 
                             const std::string& email, 
                             const std::string& name, 
                             const std::string& password, 
                             const std::string& university, 
                             const std::string& department = "") override;
    
        bool loginAccount(const std::string& role, 
                          const std::string& email, 
                          const std::string& password) override;
    
        // Hàm cụ thể cho student/lecturer
        bool registerStudent(const std::string& email, const std::string& name, University::Name university, const std::string& password);
        bool registerLecturer(const std::string& email, const std::string& name, Department department, University::Name university, const std::string& password);
    
        bool loginStudent(const std::string& email, const std::string& password);
        bool loginLecturer(const std::string& email, const std::string& password);
    
    private:
        bool validateLogin(const std::string& email, const std::string& password, bool isLecturer);
    
        std::string _studentFile;
        std::string _lecturerFile;
};
    
#endif
