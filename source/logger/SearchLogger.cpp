#include "SearchLogger.h"
#include "../time/Time.h"

SearchLogger& SearchLogger::intance() {
    static SearchLogger _instance;
    return _instance;
}

void SearchLogger::log(const std::string& query) {
    std::ofstream logFile(LOG_SEARCH_PATH, std::ios::app);
    if (!logFile.is_open()) {
        throw std::runtime_error("Failed to open log search file");
    }
    std::string timestamp = Time::getCurrentTime();
    std::string formatLog = timestamp + "|" + query + "\n";
    logFile << formatLog;
    logFile.close();
}