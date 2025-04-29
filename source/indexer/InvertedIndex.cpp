#include "InvertedIndex.h"
#include "../text/TextProcessor.h"

void InvertedIndex::indexDocument(const std::string& documentId, const std::string& content) {
    std::stringstream ss(content);
    std::string token;
    while (ss >> token) {
        token = TextProcessor::toLower(token);
        _indexs[token].insert(documentId);
    }
}

void InvertedIndex::removeIndex(const std::string& documentId) {
    for (auto& pair : _indexs) {
        pair.second.erase(documentId);
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