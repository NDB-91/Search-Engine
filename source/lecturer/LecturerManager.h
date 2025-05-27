#ifndef _LECTURER_MANAGER_H_
#define _LECTURER_MANAGER_H_

#include <fstream>
#include <string>
#include <unordered_map>

#include "../Object.h"
#include "Lecturer.h"
#include "../department/Department.h"
#include "../university/University.h"

#define LECTURERS "database/entity/lecturers.txt"

/**
 * @file LecturerManager.h
 * @brief Defines the LecturerManager class for managing lecturer information.
 */

/**
 * @class LecturerManager
 * @brief Singleton class for managing lecturers in the system.
 * 
 * The LecturerManager class provides methods to add, retrieve, and manage lecturer information.
 * It ensures that lecturer data is loaded from and saved to persistent storage.
 */
class LecturerManager : public Object {
public:
    /**
     * @brief Gets the singleton instance of the LecturerManager.
     * @return A reference to the LecturerManager instance.
     */
    static LecturerManager& instance();

    /**
     * @brief Adds a new lecturer to the system.
     * 
     * @param lecturer The Lecturer object to be added.
     */
    void addLecturer(const Lecturer& lecturer);

    /**
     * @brief Retrieves the name of a lecturer by their email.
     * 
     * @param email The email address of the lecturer.
     * @return The name of the lecturer as a string.
     */
    std::string getLecturerName(const std::string& email) const;

    /**
     * @brief Retrieves a Lecturer object by their email.
     * 
     * @param email The email address of the lecturer.
     * @return A reference to the Lecturer object.
     */
    Lecturer& getLecturer(const std::string& email);

    /**
     * @brief Deleted copy constructor to enforce the singleton pattern.
     */
    LecturerManager(const LecturerManager&) = delete;

    /**
     * @brief Deleted copy assignment operator to enforce the singleton pattern.
     */
    LecturerManager& operator=(const LecturerManager&) = delete;

private:
    /**
     * @brief Constructs a LecturerManager object.
     * 
     * This constructor is private to enforce the singleton pattern.
     */
    LecturerManager();

    /**
     * @brief Loads lecturer data from persistent storage.
     */
    void loadLecturers();

    /**
     * @brief Saves a lecturer's data to persistent storage.
     * 
     * @param lecturer The Lecturer object to be saved.
     */
    void saveLecturer(const Lecturer& lecturer);

    std::unordered_map<std::string, Lecturer> _lecturers; /**< A map of lecturer email addresses to Lecturer objects. */
};

#endif