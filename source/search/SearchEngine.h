#ifndef _SEARCH_ENGINE_H_
#define _SEARCH_ENGINE_H_

#include <vector>

#include "SearchBase.h"

class SearchEngine {
public:
    SearchEngine();
    ~SearchEngine();

    void search(const std::string& query);
    void displayResults();
    void clearResults();
private:
    SearchBase* _search;
    std::string _currentQuery;
    std::vector<std::string> _results;
};

#endif