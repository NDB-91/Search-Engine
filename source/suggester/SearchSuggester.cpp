#include "SearchSuggester.h"

SearchSuggester::SearchSuggester() {
    loadHistory();
}

std::vector<std::string> SearchSuggester::suggest(const std::string& prefix) {
    loadHistory();
    std::vector<std::string> results;
    TrieNode* node = _trieRoot;
    for(char c : prefix){
        int index = c - 'a';
        if(node->childrens[index] == nullptr) {
            return results;
        }
        else {
            node = node->childrens[index];
        }
    }
    collectSuggestions(node, prefix, results);
    return results;
}

void SearchSuggester::loadHistory() {
    _trieRoot = nullptr;
    std::ifstream logFile(LOG_SEARCH_PATH);
    std::string line;
    while (std::getline(logFile, line)) {
        auto pos = line.find('|');
        if (pos != std::string::npos && pos + 1 < line.size()) {
            std::string query = line.substr(pos + 1);
            _trie.insert(query);
        }
    }
    _trieRoot = getTrieRoot();
}

TrieNode* SearchSuggester::getTrieRoot() {
    return _trie.getRoot();
}

void SearchSuggester::collectSuggestions(TrieNode* node, std::string word, std::vector<std::string>& results) {
    if (!node) {
        return;
    }
    if (node->endOfWord) {
        results.push_back(word);
    }
    for (int i = 0; i < 26; ++i) {
        if (node->childrens[i]) {
            char c = 'a' + i;
            collectSuggestions(node->childrens[i], word + c, results);
        }
    }
}