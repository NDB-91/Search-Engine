#ifndef _INVERTED_INDEX_H_
#define _INVERTED_INDEX_H_

#include <unordered_map>
#include <unordered_set>
#include <sstream>

#include "IIndex.h"

class InvertedIndex : public IIndex {
public:
    InvertedIndex() = default;
    ~InvertedIndex() override = default;

    void indexDocument(const Document& document) override;
    void removeIndex(const Document& document) override;
    std::vector<std::string> search(const std::string& query) override;
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> _indexs;
};

#endif