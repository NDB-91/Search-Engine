#ifndef _TFIDF_H_
#define _TFIDF_H_

#include <fstream>
#include <math.h>
#include <algorithm>

#include "ITermFrequency.h"
#include "IInverseDocumentFrequency.h"

/**
 * @file TFIDF.h
 * @brief Defines the TFIDF class for calculating Term Frequency-Inverse Document Frequency (TF-IDF) values.
 */

/**
 * @class TFIDF
 * @brief Implements the ITermFrequency and IInverseDocumentFrequency interfaces to calculate TF-IDF values.
 * 
 * The TFIDF class provides methods to calculate Term Frequency (TF), Inverse Document Frequency (IDF),
 * and the combined TF-IDF value for terms in documents.
 */
class TFIDF : public ITermFrequency, public IInverseDocumentFrequency {
public:
    /**
     * @brief Gets the singleton instance of the TFIDF.
     * @return A reference to the TFIDF instance.
     */
    static TFIDF& instance();

    /**
     * @brief Destroys the TFIDF object.
     */
    ~TFIDF() override = default;

    /**
     * @brief Calculates the term frequency (TF) of a term in a document.
     * 
     * @param document The document in which the term frequency is to be calculated.
     * @param term The term for which the TF is to be calculated.
     * @return The TF value as a float.
     */
    float calculateTF(const Document& document, const std::string& term) const override;

    /**
     * @brief Calculates the inverse document frequency (IDF) of a term.
     * 
     * @param term The term for which the IDF is to be calculated.
     * @return The IDF value as a float.
     */
    float calculateIDF(const std::string& term) const override;

    /**
     * @brief Calculates the TF-IDF value of a term in a document.
     * 
     * @param document The document in which the TF-IDF is to be calculated.
     * @param term The term for which the TF-IDF is to be calculated.
     * @return The TF-IDF value as a float.
     */
    float calculateTFIDF(const Document& document, const std::string& term) const;
};

#endif