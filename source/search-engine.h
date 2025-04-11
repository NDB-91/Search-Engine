#ifndef _SEARCH_ENGINE_H
#define _SEARCH_ENGINE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class SearchEngine {
public:
    SearchEngine();
    ~SearchEngine();

    void search(const std::string& query);
    void displayResults();
    void saveResults(const std::string& filename);
    void loadResults(const std::string& filename);
    void clearResults();

private:
    std::vector<std::string> results;
    std::string currentQuery;
    std::string currentFilename;
    bool resultsLoaded;
    bool resultsSaved;

    void processQuery(const std::string& query);
    void formatResults();
};

#endif