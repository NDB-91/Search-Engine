#include <iostream>

#include "SearchEngine.h"
#include "SearchKeyword.h"
#include "../text/TextProcessor.h"

SearchEngine::SearchEngine() {
    _search = std::make_shared<SearchKeyword>();
}

void SearchEngine::search(const std::string& query) {
    _currentQuery = query;
    _results = _search->search(TextProcessor::toLower(query));
}

std::vector<std::string> SearchEngine::results() {
    return _results;
}

void SearchEngine::displayResults() {
    std::cout << "The results for the query " << _currentQuery << " are:\n";
    for(const auto& result : _results) {
        std::cout << result << "\n";
    }
}

void SearchEngine::clearResults() {
    _results.clear();
}