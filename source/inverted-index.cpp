#include "inverted-index.h"

void InvertedIndex::indexDocument(const std::string& documentId, const std::string& content) {
    auto tokens = TextProcessor::tokenize(TextProcessor::toLower(content));
    for (const auto& token : tokens) {
        _index[token].insert(documentId);
    }
}

std::unordered_set<std::string> InvertedIndex::search(const std::string& query) const {
    auto tokens = TextProcessor::tokenize(TextProcessor::toLower(query));
    std::unordered_set<std::string> results;

    for (const auto& token : tokens) {
        auto it = _index.find(token);
        if (it != _index.end()) {
            results.insert(it->second.begin(), it->second.end());
        }
    }

    return results;
}