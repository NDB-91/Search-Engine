#ifndef _TIME_H_
#define _TIME_H_

#include <string>
#include <sstream>
#include <chrono>
#include <iomanip>

/**
 * @file Time.h
 * @brief Defines the Time class for retrieving the current time.
 */

/**
 * @class Time
 * @brief Provides a static method to retrieve the current time as a string.
 * 
 * The Time class includes a utility method to get the current system time
 * formatted as a string.
 */
class Time {
public:
    /**
     * @brief Retrieves the current system time.
     * 
     * @return A string representing the current time.
     */
    static std::string getCurrentTime();
};

#endif