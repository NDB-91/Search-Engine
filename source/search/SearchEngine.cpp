#include <iostream>

#include "SearchEngine.h"
#include "SearchKeyword.h"
#include "../document/DocumentManager.h"
#include "../text/TextProcessor.h"

SearchEngine::SearchEngine() {
    _search = std::make_shared<SearchKeyword>();
}

void SearchEngine::search(const std::string& query) {
    _currentQuery = query;
    _results = _search->search(TextProcessor::toLower(query));
}

void SearchEngine::displayResults() {
    std::cout << "--- The results for the query '" << _currentQuery << "' ---\n";
    for(int i = 0; i < _results.size(); ++i) {
        std::string title = DocumentManager::instance().getDocument(_results[i]).title();
        std::cout << i + 1 << ". " << title << "\n";
    }
    std::cout << "\n";
}

void SearchEngine::clearResults() {
    _results.clear();
}