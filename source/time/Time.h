#ifndef _TIME_H_
#define _TIME_H_

#include <string>
#include <sstream>
#include <chrono>
#include <iomanip>

class Time {
public:
    static std::string getCurrentTime();
};

#endif