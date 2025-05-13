#ifndef _SEARCHLOGGER_H_
#define _SEARCHLOGGER_H_

#include "ILogger.h"

#define LOG_SEARCH_PATH "database/log/log.txt"

/**
 * @file SearchLogger.h
 * @brief Defines the SearchLogger class for logging search queries.
 */

/**
 * @class SearchLogger
 * @brief Implements the ILogger interface to log search queries.
 * 
 * The SearchLogger class provides functionality to log search queries to a specified file.
 */
class SearchLogger : public ILogger {
public:
    /**
     * @brief Gets the singleton instance of the SearchLogger.
     * @return A reference to the SearchLogger instance.
     */
    static SearchLogger& intance();

    /**
     * @brief Destroys the SearchLogger object.
     */
    ~SearchLogger() override = default;

    /**
     * @brief Logs a search query.
     * 
     * @param query The search query to be logged.
     */
    void log(const std::string& query);
};

#endif