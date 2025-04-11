#include "search-engine.h"

SearchEngine::SearchEngine() {

}

SearchEngine::~SearchEngine() {

}

void SearchEngine::search(const std::string& query) {
    currentQuery = query;
    processQuery(query);
}

void SearchEngine::displayResults() {
    if (results.empty()) {
        std::cout << "No results found for query: " << currentQuery << "\n";
    } else {
        std::cout << "Search results for query: " << currentQuery << "\n";
        for (const auto& result : results) {
            std::cout << result << "\n";
        }
    }
}

void SearchEngine::saveResults(const std::string& filename) {
    currentFilename = filename;
    // Save results to file
    resultsSaved = true;
}

void SearchEngine::loadResults(const std::string& filename) {
    currentFilename = filename;
    // Load results from file
    resultsLoaded = true;
}

void SearchEngine::clearResults() {
    results.clear();
    currentQuery.clear();
    currentFilename.clear();
    resultsLoaded = false;
    resultsSaved = false;
}

void SearchEngine::processQuery(const std::string& query) {
    // Simulate processing the query and generating results
    results.push_back("Result 1 for " + query);
    results.push_back("Result 2 for " + query);
    results.push_back("Result 3 for " + query);
}

void SearchEngine::formatResults() {
    // Format results for display
    for (auto& result : results) {
        result = "Formatted: " + result;
    }
}