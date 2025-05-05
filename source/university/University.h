#ifndef _UNIVERSITY_H_
#define _UNIVERSITY_H_

#include <string>

/**
 * @file University.h
 * @brief Defines the University class for representing university information.
 */

/**
 * @class University
 * @brief Represents a university and its associated details.
 * 
 * The University class provides methods to access university details, such as its name.
 */
class University {
public:
    /**
     * @enum Name
     * @brief Enumeration of university names.
     * 
     * This enumeration lists the supported university names.
     */
    enum class Name {
        HCMUS,   /**< Ho Chi Minh University of Science. */
        USSH,    /**< University of Social Sciences and Humanities. */
        UIT,     /**< University of Information Technology. */
        HCMUT,   /**< Ho Chi Minh University of Technology. */
        HCMUTE,  /**< Ho Chi Minh University of Technical Education. */
        NEU,     /**< National Economics University. */
        FTU,     /**< Foreign Trade University. */
        Unknown  /**< Unknown university. */
    };

    /**
     * @brief Constructs a University object with the specified name.
     * 
     * @param name The name of the university.
     */
    University(const Name& name);

    /**
     * @brief Destroys the University object.
     */
    ~University();

    /**
     * @brief Gets the name of the university.
     * 
     * @return The name of the university as a Name enumeration value.
     */
    Name name() const;

private:
    Name _name; /**< The name of the university. */
};

#endif