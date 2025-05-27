#ifndef _ISUGGESTER_H_
#define _ISUGGESTER_H_

#include <string>
#include <vector>

#include "../Object.h"

/**
 * @file ISuggester.h
 * @brief Defines the ISuggester interface for providing suggestions.
 */

/**
 * @class ISuggester
 * @brief Interface for providing suggestions.
 * 
 * The ISuggester interface serves as a base for implementing suggestion functionality.
 * Derived classes can define specific methods for generating suggestions.
 */
class ISuggester : public Object {
public:
    /**
     * @brief Virtual destructor for the ISuggester interface.
     */
    virtual ~ISuggester() = default;
    virtual std::vector<std::string> suggest(const std::string& prefix) = 0;
};

#endif