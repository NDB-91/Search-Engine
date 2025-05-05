#ifndef _SEARCH_KEYWORD_H_
#define _SEARCH_KEYWORD_H_

#include "SearchBase.h"

#define DIRECTORY_PATH "database/reference/"

/**
 * @file SearchKeyword.h
 * @brief Defines the SearchKeyword class for performing keyword-based search queries.
 */

/**
 * @class SearchKeyword
 * @brief Implements keyword-based search functionality.
 * 
 * The SearchKeyword class derives from SearchBase and provides an implementation
 * for performing search queries based on keywords.
 */
class SearchKeyword : public SearchBase {
public:
    /**
     * @brief Constructs a SearchKeyword object.
     */
    SearchKeyword();

    /**
     * @brief Destroys the SearchKeyword object.
     */
    ~SearchKeyword() override = default;

    /**
     * @brief Performs a keyword-based search query.
     * 
     * @param query The search query string.
     * @return A vector of document identifiers matching the query.
     */
    std::vector<std::string> search(const std::string& query) override;
};

#endif