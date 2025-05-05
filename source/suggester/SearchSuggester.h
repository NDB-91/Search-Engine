#ifndef _SEARCHSUGGESTER_H_
#define _SEARCHSUGGESTER_H_

#include "ISuggester.h"

/**
 * @file SearchSuggester.h
 * @brief Defines the SearchSuggester class for providing search suggestions.
 */

/**
 * @class SearchSuggester
 * @brief Implements the ISuggester interface to provide search suggestions.
 * 
 * The SearchSuggester class provides functionality for generating suggestions
 * based on user input or search history.
 */
class SearchSuggester : public ISuggester {
public:
    /**
     * @brief Destroys the SearchSuggester object.
     */
    ~SearchSuggester() override = default;
};

#endif