#ifndef _TEXT_PROCESSOR_H_
#define _TEXT_PROCESSOR_H_

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

/**
 * @file TextProcessor.h
 * @brief Defines the TextProcessor class for text processing operations.
 */

/**
 * @class TextProcessor
 * @brief Provides static methods for processing text.
 * 
 * The TextProcessor class includes utility methods for converting text to lowercase
 * and tokenizing text into individual words.
 */
class TextProcessor {
public:
    /**
     * @brief Deleted default constructor to prevent instantiation.
     */
    TextProcessor() = delete;

    /**
     * @brief Converts a string to lowercase.
     * 
     * @param text The input string to be converted.
     * @return A new string with all characters in lowercase.
     */
    static std::string toLower(const std::string& text);

    /**
     * @brief Tokenizes a string into individual words.
     * 
     * @param text The input string to be tokenized.
     * @return A vector of strings, where each string is a token (word).
     */
    static std::vector<std::string> tokenize(const std::string& text);
};

#endif