#ifndef _IINDEX_H_
#define _IINDEX_H_

#include <vector>
#include <string>

#include "../document/Document.h"

class IIndex {
public:
    virtual ~IIndex() = default;
    virtual void indexDocument(const Document& document) = 0;
    virtual void removeIndex(const Document& document) = 0;
    virtual std::vector<std::string> search(const std::string& query) = 0;
};

#endif