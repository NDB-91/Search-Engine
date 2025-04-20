#ifndef _TEXT_PROCESSOR_H_
#define _TEXT_PROCESSOR_H_

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class TextProcessor {
public:
    TextProcessor() = delete;

    static std::string toLower(const std::string& text);
    static std::vector<std::string> tokenize(const std::string& text);
};

#endif