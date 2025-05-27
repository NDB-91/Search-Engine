#ifndef _SEARCH_BASE_H_
#define _SEARCH_BASE_H_

#include <memory>
#include <vector>
#include <string>

#include "../Object.h"
#include "../indexer/IIndexBuilder.h"
#include "IndexSearcher.h"

/**
 * @file SearchBase.h
 * @brief Defines the SearchBase abstract class for performing search queries.
 */

/**
 * @class SearchBase
 * @brief Abstract base class for performing search queries.
 * 
 * The SearchBase class provides a common interface for search functionality.
 * Derived classes must implement the `search` method to perform specific search operations.
 */
class SearchBase : public Object {
public:
    /**
     * @brief Virtual destructor for the SearchBase class.
     */
    virtual ~SearchBase() = default;

    /**
     * @brief Performs a search query.
     * 
     * @param query The search query string.
     * @return A vector of document identifiers matching the query.
     */
    virtual std::vector<std::string> search(const std::string& query) = 0;

protected:
    std::shared_ptr<IIndexBuilder> _indexBuilder; /**< The index builder used for constructing the index. */
    IndexSearcher _indexSearcher;                /**< The index searcher used for performing search queries. */
};

#endif