#include "search-engine.h"

SearchEngine::SearchEngine(const std::string& directoryPath) 
    : _currentQuery(""), _currentFilename(""), _resultsLoaded(false), _resultsSaved(false) {
    
    _directoryPath = directoryPath;
    buildIndex();
}

SearchEngine::~SearchEngine() {

}

void SearchEngine::buildIndex() {
    FileLoader fileLoader(_directoryPath);
    auto documents = fileLoader.loadDocuments();

    for (const auto& doc : documents) {
        _index.indexDocument(doc.first, doc.second);
    }
}

void SearchEngine::search(const std::string& query) {
    _currentQuery = query;
    processQuery(query);
}

void SearchEngine::displayResults() {
    if (_results.empty()) {
        std::cout << "No results found for query: " << _currentQuery << "\n";
    } else {
        std::cout << "Search results for query: " << _currentQuery << "\n";
        for (const auto& result : _results) {
            std::cout << result << "\n";
        }
    }
}

void SearchEngine::saveResults(const std::string& filename) {
    _currentFilename = filename;
    // Save results to file
    _resultsSaved = true;
}

void SearchEngine::loadResults(const std::string& filename) {
    _currentFilename = filename;
    // Load results from file
    _resultsLoaded = true;
}

void SearchEngine::clearResults() {
    _results.clear();
    _currentQuery.clear();
    _currentFilename.clear();
    _resultsLoaded = false;
    _resultsSaved = false;
}

void SearchEngine::processQuery(const std::string& query) {
    _results = _index.search(query);
    formatResults();
}

void SearchEngine::formatResults() {
    
}