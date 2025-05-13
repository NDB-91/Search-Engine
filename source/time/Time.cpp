#include "Time.h"

std::string Time::getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::tm tm_buf;
#ifdef _WIN32
    localtime_s(&tm_buf, &time); // Windows secure version
#else
    localtime_r(&time, &tm_buf); // POSIX thread-safe version
#endif
    std::ostringstream oss;
    oss << std::put_time(&tm_buf, "%Y-%m-%d %H:%M:%S UTC");
    return oss.str();
}