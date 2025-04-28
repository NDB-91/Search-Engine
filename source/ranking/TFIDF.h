#ifndef _TFIDF_H_
#define _TFIDF_H_

#include <fstream>
#include <math.h>
#include <algorithm>

#include "ITermFrequency.h"
#include "IInverseDocumentFrequency.h"

class TFIDF : public ITermFrequency, public IInverseDocumentFrequency {
public:
    ~TFIDF() override = default;

    float calculateTF(const Document& document, const std::string& term) const override;
    float calculateIDF(const std::string& term) const override;
    
    float calculateTFIDF(const Document& document, const std::string& term) const;
};

#endif