#ifndef _SEARCHLOGGER_H_
#define _SEARCHLOGGER_H_

#include "ILogger.h"

#define LOG_SEARCH_PATH "../database/log/log.txt"

class SearchLogger : public ILogger {
public:
    ~SearchLogger() override = default;

    void log(const std::string& query) override;
};

#endif