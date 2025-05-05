#ifndef _IINDEX_H_
#define _IINDEX_H_

#include <vector>
#include <string>

#include "../document/Document.h"

/**
 * @file IIndex.h
 * @brief Defines the IIndex interface for indexing and querying documents.
 */

/**
 * @class IIndex
 * @brief Interface for indexing and querying documents.
 * 
 * The IIndex interface provides methods for indexing documents, removing document indices, 
 * and querying the index for relevant documents based on a search query.
 */
class IIndex {
public:
    /**
     * @brief Virtual destructor for the IIndex interface.
     */
    virtual ~IIndex() = default;

    /**
     * @brief Indexes a document.
     * 
     * @param document The document to be indexed.
     */
    virtual void indexDocument(const Document& document) = 0;

    /**
     * @brief Removes the index of a document.
     * 
     * @param document The document whose index is to be removed.
     */
    virtual void removeIndex(const Document& document) = 0;

    /**
     * @brief Queries the index for relevant documents.
     * 
     * @param query The search query string.
     * @return A vector of document identifiers matching the query.
     */
    virtual std::vector<std::string> index(const std::string& query) = 0;
};

#endif