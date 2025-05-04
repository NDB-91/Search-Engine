#include <unordered_set>

#include "InvertedIndexBuilder.h"

InvertedIndexBuilder::InvertedIndexBuilder() {
    _index = std::make_shared<InvertedIndex>();
}

void InvertedIndexBuilder::buildIndex(const Document& document) {
    _index->indexDocument(document);
}

void InvertedIndexBuilder::removeIndex(const Document& document) {
    _index->removeIndex(document);
}

std::shared_ptr<IIndex> InvertedIndexBuilder::index() const {
    return _index;
}