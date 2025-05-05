#ifndef _SEARCH_ENGINE_H_
#define _SEARCH_ENGINE_H_

#include <memory>
#include <vector>

#include "SearchBase.h"

/**
 * @file SearchEngine.h
 * @brief Defines the SearchEngine class for managing search operations.
 */

/**
 * @class SearchEngine
 * @brief Provides functionality to perform and manage search operations.
 * 
 * The SearchEngine class allows users to execute search queries, display results,
 * and clear previous search results. It uses a SearchBase-derived object to perform
 * the actual search operations.
 */
class SearchEngine {
public:
    /**
     * @brief Constructs a SearchEngine object.
     */
    SearchEngine();

    /**
     * @brief Destroys the SearchEngine object.
     */
    ~SearchEngine() = default;

    /**
     * @brief Performs a search query.
     * 
     * @param query The search query string.
     */
    void search(const std::string& query);

    /**
     * @brief Displays the search results.
     */
    void displayResults();

    /**
     * @brief Clears the current search results.
     */
    void clearResults();

private:
    std::shared_ptr<SearchBase> _search; /**< The search object used to perform queries. */
    std::string _currentQuery;           /**< The current search query string. */
    std::vector<std::string> _results;   /**< The results of the current search query. */
};

#endif