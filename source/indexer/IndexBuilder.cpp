#include <unordered_set>

#include "IndexBuilder.h"
#include "Index.h"

IndexBuilder::IndexBuilder() {
    _index = new Index();
}

IndexBuilder::~IndexBuilder() {
    delete _index;
}

void IndexBuilder::buildIndex(const std::string& documentId, const std::string& content) {
    _index->indexDocument(documentId, content);
}

void IndexBuilder::removeIndex(const std::string& documentId) {
    
}

std::vector<std::string> IndexBuilder::search(const std::string& query) {
    return _index->search(query);
}