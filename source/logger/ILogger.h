#ifndef _ILOGGER_H_
#define _ILOGGER_H_

#include <fstream>
#include <string>

/**
 * @file ILogger.h
 * @brief Defines the ILogger interface for logging messages.
 */

/**
 * @class ILogger
 * @brief Interface for logging messages.
 * 
 * The ILogger interface provides a method to log messages. Implementations
 * of this interface can define how and where the messages are logged.
 */
class ILogger {
public:
    /**
     * @brief Virtual destructor for the ILogger interface.
     */
    virtual ~ILogger() = default;

    /**
     * @brief Logs a message.
     * 
     * @param str The message to be logged.
     */
    virtual void log(const std::string& str) = 0;
};

#endif