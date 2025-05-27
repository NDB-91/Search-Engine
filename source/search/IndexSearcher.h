#ifndef _INDEX_SEARCHER_H_
#define _INDEX_SEARCHER_H_

#include <memory>
#include <string>
#include <vector>

#include "../Object.h"
#include "../indexer/IIndex.h"
#include "../indexer/IIndexBuilder.h"

/**
 * @file IndexSearcher.h
 * @brief Defines the IndexSearcher class for performing search queries on an index.
 */

/**
 * @class IndexSearcher
 * @brief Provides functionality to search for documents in an index.
 * 
 * The IndexSearcher class allows users to perform search queries on an index
 * built using an IIndexBuilder. It retrieves document identifiers that match
 * the given search query.
 */
class IndexSearcher : public Object {
public:
    /**
     * @brief Constructs an IndexSearcher object with no index.
     */
    IndexSearcher();

    /**
     * @brief Constructs an IndexSearcher object with a specified index builder.
     * 
     * @param indexBuilder A shared pointer to an IIndexBuilder used to build the index.
     */
    explicit IndexSearcher(const std::shared_ptr<IIndexBuilder>& indexBuilder);

    /**
     * @brief Searches the index for documents matching the query.
     * 
     * @param query The search query string.
     * @return A vector of document identifiers matching the query.
     */
    std::vector<std::string> search(const std::string& query) const;

private:
    std::shared_ptr<IIndex> _index; /**< The index used for performing search queries. */
};

#endif