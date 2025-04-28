#include "Search.h"
#include "../indexer/IndexManager.h"

std::vector<std::string> Search::search(const std::string& query) {
    IndexManager::instance().buildIndexDirectory(DIRECTORY_PATH);
    return IndexManager::instance().search(query);
}