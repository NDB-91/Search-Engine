#ifndef _ITEM_FREQUENCY_H_
#define _ITEM_FREQUENCY_H_

#include <string>
#include <unordered_map>

#include "../document/Document.h"

class ITermFrequency {
public:
    virtual ~ITermFrequency() = default;

    virtual float calculateTF(const Document& document, const std::string& term) const = 0;
};

#endif