#include "TextProcessor.h"

std::string TextProcessor::toLower(const std::string& text) {
    std::string lowerText = text;
    std::transform(lowerText.begin(), lowerText.end(), lowerText.begin(), ::tolower);
    return lowerText;
}

std::vector<std::string> TextProcessor::tokenize(const std::string& text) {
    std::stringstream ss(text);
    std::vector<std::string> tokens;
    std::string token;

    while (ss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}