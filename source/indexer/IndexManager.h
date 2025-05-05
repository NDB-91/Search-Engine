#ifndef _INDEX_MANAGER_H_
#define _INDEX_MANAGER_H_

#include <string>
#include <vector>
#include <unordered_set>

#include "IIndexBuilder.h"

/**
 * @file IndexManager.h
 * @brief Defines the IndexManager class for managing the indexing process.
 */

/**
 * @class IndexManager
 * @brief Singleton class for managing the indexing process.
 * 
 * The IndexManager class provides methods to build indices for a collection of documents
 * using a specified index builder. It enforces the singleton pattern to ensure a single
 * instance of the manager.
 */
class IndexManager {
public:
    /**
     * @brief Gets the singleton instance of the IndexManager.
     * @return A reference to the IndexManager instance.
     */
    static IndexManager& instance();

    /**
     * @brief Builds an index for a collection of documents.
     * 
     * @param documents A vector of  Document objects to be indexed.
     * @param indexBuilder A shared pointer to the IIndexBuilder used to build the index.
     * @return A shared pointer to the built IIndex object.
     */
    std::shared_ptr<IIndex> buildIndex(const std::vector<Document>& documents, std::shared_ptr<IIndexBuilder> indexBuilder);

    /**
     * @brief Deleted copy constructor to enforce the singleton pattern.
     */
    IndexManager(const IndexManager& indexManager) = delete;

    /**
     * @brief Deleted copy assignment operator to enforce the singleton pattern.
     */
    IndexManager& operator=(const IndexManager& indexManager) = delete;

private:
    /**
     * @brief Constructs an IndexManager object.
     * 
     * This constructor is private to enforce the singleton pattern.
     */
    IndexManager();
};

#endif