#ifndef _IINVERSE_DOCUMENT_FREQUENCY_H_
#define _IINVERSE_DOCUMENT_FREQUENCY_H_

#include <string>
#include <vector>

/**
 * @file IInverseDocumentFrequency.h
 * @brief Defines the IInverseDocumentFrequency interface for calculating the inverse document frequency (IDF) of terms.
 */

/**
 * @class IInverseDocumentFrequency
 * @brief Interface for calculating the inverse document frequency (IDF) of terms.
 * 
 * The IInverseDocumentFrequency interface provides a method to calculate the IDF value
 * for a given term. Implementations of this interface can define how the IDF is computed.
 */
class IInverseDocumentFrequency {
public:
    /**
     * @brief Virtual destructor for the IInverseDocumentFrequency interface.
     */
    virtual ~IInverseDocumentFrequency() = default;

    /**
     * @brief Calculates the inverse document frequency (IDF) of a term.
     * 
     * @param term The term for which the IDF is to be calculated.
     * @return The IDF value as a float.
     */
    virtual float calculateIDF(const std::string& term) const = 0;
};

#endif