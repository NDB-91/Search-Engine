#ifndef _INDEX_MANAGER_H_
#define _INDEX_MANAGER_H_

#include <string>
#include <unordered_set>

#include "IndexBuilder.h"
#include "../loader/ILoader.h"

class IndexManager {
public:
    IndexManager();
    ~IndexManager();

    void addDocument(const std::string& documentId);
    void removeDocument(const std::string& documentId);
    void buildIndexDirectory(const std::string& directoryPath);

    std::vector<std::string> search(const std::string& query);
private:
    IndexBuilder* _indexBuilder;
    ILoader* _loader;
    std::string _directoryPath;
    std::unordered_set<std::string> _indexed;
};

#endif