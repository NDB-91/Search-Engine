#ifndef _INVERTED_INDEX_H_
#define _INVERTED_INDEX_H_

#include <unordered_map>
#include <unordered_set>
#include <string>

#include "text-processor.h"

class InvertedIndex {
public:
    void indexDocument(const std::string& documentId, const std::string& content);
    std::unordered_set<std::string> search(const std::string& query) const;

private:
    std::unordered_map<std::string, std::unordered_set<std::string>> _index;
};

#endif