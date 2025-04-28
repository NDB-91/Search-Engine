#ifndef _INDEX_MANAGER_H_
#define _INDEX_MANAGER_H_

#include <memory>
#include <string>
#include <unordered_set>

#include "IndexBuilder.h"

class IndexManager {
public:
    static IndexManager& instance();

    void addDocument(const std::string& documentId);
    void removeDocument(const std::string& documentId);
    void buildIndexDirectory(const std::string& directoryPath);

    std::vector<std::string> search(const std::string& query);
private:
    IndexManager();

    std::shared_ptr<IndexBuilder> _indexBuilder;
    std::string _directoryPath;
    std::unordered_set<std::string> _indexed;
};

#endif