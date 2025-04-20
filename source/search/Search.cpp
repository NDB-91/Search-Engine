#include "Search.h"

Search::Search() {
    _indexManager = new IndexManager();
}

Search::~Search() {
    delete _indexManager;
}

std::vector<std::string> Search::search(const std::string& query) {
    _indexManager->buildIndexDirectory(DIRECTORY_PATH);
    return _indexManager->search(query);
}