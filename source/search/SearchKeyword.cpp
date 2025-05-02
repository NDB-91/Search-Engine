#include "SearchKeyword.h"
#include "../indexer/IndexManager.h"
#include "../indexer/InvertedIndexBuilder.h"

SearchKeyword::SearchKeyword() {
    _indexBuilder = std::make_shared<InvertedIndexBuilder>();
    _indexSearcher = IndexSearcher(_indexBuilder);
}

std::vector<std::string> SearchKeyword::search(const std::string& query) {
    return _indexSearcher.search(query);
}