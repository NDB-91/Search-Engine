#ifndef _SEARCH_ENGINE_H
#define _SEARCH_ENGINE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>

#include "file-loader.h"
#include "inverted-index.h"

class SearchEngine {
public:
    explicit SearchEngine(const std::string& directoryPath);
    ~SearchEngine();

    void buildIndex();
    void search(const std::string& query);
    void displayResults();
    void saveResults(const std::string& filename);
    void loadResults(const std::string& filename);
    void clearResults();

private:
    std::string _directoryPath;
    InvertedIndex _index;
    std::unordered_set<std::string> _results;
    std::string _currentQuery;
    std::string _currentFilename;
    bool _resultsLoaded;
    bool _resultsSaved;

    void processQuery(const std::string& query);
    void formatResults();
};

#endif