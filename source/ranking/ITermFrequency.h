#ifndef _ITEM_FREQUENCY_H_
#define _ITEM_FREQUENCY_H_

#include <string>
#include <unordered_map>

#include "../document/Document.h"

/**
 * @file ITermFrequency.h
 * @brief Defines the ITermFrequency interface for calculating the term frequency (TF) of terms in a document.
 */

/**
 * @class ITermFrequency
 * @brief Interface for calculating the term frequency (TF) of terms in a document.
 * 
 * The ITermFrequency interface provides a method to calculate the TF value for a given term
 * in a specific document. Implementations of this interface can define how the TF is computed.
 */
class ITermFrequency {
public:
    /**
     * @brief Virtual destructor for the ITermFrequency interface.
     */
    virtual ~ITermFrequency() = default;

    /**
     * @brief Calculates the term frequency (TF) of a term in a document.
     * 
     * @param document The document in which the term frequency is to be calculated.
     * @param term The term for which the TF is to be calculated.
     * @return The TF value as a float.
     */
    virtual float calculateTF(const Document& document, const std::string& term) const = 0;
};

#endif