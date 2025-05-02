#include <iostream>
#include <filesystem>

#include "IndexManager.h"
#include "../loader/LoaderFile.h"

IndexManager& IndexManager::instance() {
    static IndexManager _instance;
    return _instance;
}

std::shared_ptr<IIndex> IndexManager::buildIndex(const std::vector<std::shared_ptr<Document>>& documents, std::shared_ptr<IIndexBuilder> indexBuilder) {
    for(auto& document : documents) {
       indexBuilder->buildIndex(*document);
    }
    return indexBuilder->index();
}

IndexManager::IndexManager() {
    
}