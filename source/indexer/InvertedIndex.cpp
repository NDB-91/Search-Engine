#include "InvertedIndex.h"
#include "../text/TextProcessor.h"
#include "../loader/LoaderFile.h"

void InvertedIndex::indexDocument(const Document& document) {
    std::string content = document.content();
    content = TextProcessor::toLower(content);
    std::stringstream ss(content);
    std::string token;
    while (ss >> token) {
        _indexs[token].insert(document.id());
    }
}

void InvertedIndex::removeIndex(const Document& document) {
    for (auto& pair : _indexs) {
        pair.second.erase(document.id());
    }
}

std::vector<std::string> InvertedIndex::search(const std::string& query) {
    std::vector<std::string> results;
    std::stringstream ss(query);
    std::string token;
    while (ss >> token) {
        token = TextProcessor::toLower(token);
        if (_indexs.find(token) != _indexs.end()) {
            results.insert(results.begin(), _indexs[token].begin(), _indexs[token].end());
        }
    }
    return results;
}