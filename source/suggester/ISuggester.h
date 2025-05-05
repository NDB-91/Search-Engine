#ifndef _ISUGGESTER_H_
#define _ISUGGESTER_H_

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
class ISuggester {
public:
    /**
     * @brief Virtual destructor for the ISuggester interface.
     */
    virtual ~ISuggester() = default;
};

#endif