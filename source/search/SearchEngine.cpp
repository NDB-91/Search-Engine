#include <iostream>
#include <format>

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

void SearchEngine::displayResults() {
    std::cout << std::format(
        "The results for the query \"{}\" are:\n",
        _currentQuery
    );
    for(const auto& result : _results) {
        std::cout << result << "\n";
    }
}

void SearchEngine::clearResults() {
    _results.clear();
}