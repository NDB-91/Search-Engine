#ifndef _STUDENT_MANAGER_H_
#define _STUDENT_MANAGER_H_

#include <fstream>
#include <vector>
#include <unordered_map>

#include "../Object.h"
#include "Student.h"
#include "../university/University.h"

#define STUDENTS "database/entity/students.txt"

/**
 * @file StudentManager.h
 * @brief Defines the StudentManager class for managing student information.
 */

/**
 * @class StudentManager
 * @brief Singleton class for managing students in the system.
 * 
 * The StudentManager class provides methods to add, retrieve, and manage student information.
 * It ensures that student data is loaded from and saved to persistent storage.
 */
class StudentManager : public Object {
public:
    /**
     * @brief Gets the singleton instance of the StudentManager.
     * @return A reference to the StudentManager instance.
     */
    static StudentManager& instance();

    /**
     * @brief Adds a new student to the system.
     * 
     * @param student The Student object containing student details.
     */
    void addStudent(const Student& student);

    /**
     * @brief Retrieves the name of a student by their email.
     * 
     * @param email The email address of the student.
     * @return The name of the student as a string.
     */
    std::string getStudentName(const std::string& email) const;

    /**
     * @brief Retrieves a Student object by their email.
     * 
     * @param email The email address of the student.
     * @return A reference to the Student object.
     */
    Student& getStudent(const std::string& email);

    /**
     * @brief Deleted copy constructor to enforce the singleton pattern.
     */
    StudentManager(const StudentManager&) = delete;

    /**
     * @brief Deleted copy assignment operator to enforce the singleton pattern.
     */
    StudentManager& operator=(const StudentManager&) = delete;

private:
    /**
     * @brief Constructs a StudentManager object.
     * 
     * This constructor is private to enforce the singleton pattern.
     */
    StudentManager();

    /**
     * @brief Loads student data from persistent storage.
     */
    void loadStudents();

    /**
     * @brief Saves a student's data to persistent storage.
     * 
     * @param student The Student object to be saved.
     */
    void saveStudent(const Student& student);

    std::unordered_map<std::string, Student> _students; /**< A map of student email addresses to Student objects. */
};

#endif
