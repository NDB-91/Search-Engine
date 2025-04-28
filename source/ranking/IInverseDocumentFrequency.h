#ifndef _IINVERSE_DOCUMENT_FREQUENCY_H_
#define _IINVERSE_DOCUMENT_FREQUENCY_H_

#include <string>
#include <vector>

class IInverseDocumentFrequency {
public:
    virtual ~IInverseDocumentFrequency() = default;

    virtual float calculateIDF(const std::string& term) const = 0;
};

#endif