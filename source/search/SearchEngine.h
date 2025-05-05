#ifndef _SEARCH_ENGINE_H_
#define _SEARCH_ENGINE_H_

#include <memory>
#include <vector>

#include "SearchBase.h"

class SearchEngine {
public:
    SearchEngine();
    ~SearchEngine() = default;

    void search(const std::string& query);
    std::vector<std::string> results();
    void displayResults();
    void clearResults();
private:
    std::shared_ptr<SearchBase> _search;
    std::string _currentQuery;
    std::vector<std::string> _results;
};

#endif