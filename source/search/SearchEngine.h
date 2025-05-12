#ifndef _SEARCH_ENGINE_H_
#define _SEARCH_ENGINE_H_

#include <memory>
#include <vector>

#include "SearchBase.h"
#include "../visitor/IVisitable.h"
#include "../visitor/IRankingVisitor.h"

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
class SearchEngine : public std::enable_shared_from_this<SearchEngine>, public IVisitable {
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
     * @brief Retrieves the result of the current search query.
     * 
     * @return The list of Document of current search query string.
     */
    std::vector<Document>& results();

    /**
     * @brief Retrieves the current search query string.
     * 
     * @return The current search query string.
     */
    std::string currentQuery() const;

    /**
     * @brief Displays the search results.
     * 
     * @param visitor The visitor object to use for displaying results.
     */
    void displayResults(std::shared_ptr<IRankingVisitor> visitor);

    /**
     * @brief Clears the current search results.
     */
    void clearResults();

    /**
     * @brief Accepts a visitor for processing.
     * 
     * @param visitor The visitor object to accept.
     */
    void accept(std::shared_ptr<IVisitor> visitor) override;

private:
    std::shared_ptr<SearchBase> _search; /**< The search object used to perform queries. */
    std::string _currentQuery;           /**< The current search query string. */
    std::vector<Document> _results;   /**< The results of the current search query. */
};

#endif