#ifndef _IINDEX_H_
#define _IINDEX_H_

#include <vector>
#include <string>

class IIndex {
public:
    IIndex() = default;
    virtual ~IIndex() = default;

    virtual void indexDocument(const std::string& documentId, const std::string& content) = 0;
    virtual void removeIndex(const std::string& documentId) = 0;
    virtual std::vector<std::string> search(const std::string& query) = 0;
};

#endif