#include "IndexSearcher.h"
#include "../indexer/IndexManager.h"
#include "../document/DocumentManager.h"

IndexSearcher::IndexSearcher() {
    _index = nullptr;
}

IndexSearcher::IndexSearcher(const std::shared_ptr<IIndexBuilder>& indexBuilder) {
    _index = IndexManager::instance().buildIndex(DocumentManager::instance().documents(), indexBuilder);
}

std::vector<std::string> IndexSearcher::search(const std::string& query) const {
    return _index->search(query);
}