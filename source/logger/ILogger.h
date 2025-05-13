#ifndef _ILOGGER_H_
#define _ILOGGER_H_

#include <fstream>
#include <string>

/**
 * @file ILogger.h
 * @brief Defines the ILogger interface for logging informations.
 */

/**
 * @class ILogger
 * @brief Interface for logging informations.
 * 
 * The ILogger interface provides a method to log informations. Implementations
 * of this interface can define how and where the informations are logged.
 */
class ILogger {
public:
    /**
     * @brief Virtual destructor for the ILogger interface.
     */
    virtual ~ILogger() = default;
};

#endif