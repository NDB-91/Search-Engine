#ifndef _INDEX_MANAGER_H_
#define _INDEX_MANAGER_H_

#include <string>
#include <vector>
#include <unordered_set>

#include "IIndexBuilder.h"

class IndexManager {
public:
    static IndexManager& instance();

    std::shared_ptr<IIndex> buildIndex(const std::vector<std::shared_ptr<Document>>& documents, std::shared_ptr<IIndexBuilder> indexBuilder);

    IndexManager(const IndexManager& indexManager) = delete;
    IndexManager& operator=(const IndexManager& indexManager) = delete;
private:
    IndexManager();
};

#endif