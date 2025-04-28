#ifndef _ILOGGER_H_
#define _ILOGGER_H_

#include <fstream>
#include <string>

class ILogger {
public:
    virtual ~ILogger() = default;

    virtual void log(const std::string& str) = 0;
};

#endif