#ifndef _INDEX_H_
#define _INDEX_H_

#include <unordered_map>
#include <unordered_set>
#include <sstream>

#include "IIndex.h"

class Index : public IIndex {
public:
    Index() = default;
    ~Index() override = default;

    void indexDocument(const std::string& documentId, const std::string& content) override;
    void removeIndex(const std::string& documentId) override;
    std::vector<std::string> search(const std::string& query) override;
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> _indexs;
};

#endif