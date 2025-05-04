#ifndef _IUSER_H_
#define _IUSER_H_

#include <string>

/**
 * @enum Role
 * @brief Represents the role of a user in the system.
 */
enum class Role {
    Student,       ///< Represents a student user.
    Lecturer,      ///< Represents a lecturer user.
    Administrator, ///< Represents an administrator user.
};

/**
 * @class IUser
 * @brief Interface for a user in the system.
 */
class IUser {
public:
    /**
     * @brief Virtual destructor for the IUser interface.
     */
    virtual ~IUser() = default;

    /**
     * @brief Gets the email address of the user.
     * @return The email address as a string.
     */
    virtual std::string email() const = 0;

    /**
     * @brief Gets the role of the user.
     * @return The role of the user as a `Role` enum.
     */
    virtual Role role() const = 0;
};

#endif