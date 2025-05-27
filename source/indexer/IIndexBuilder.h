#ifndef _IINDEX_BUILDER_H_
#define _IINDEX_BUILDER_H_

#include <memory>
#include <string>

#include "../Object.h"
#include "IIndex.h"
#include "../document/Document.h"

/**
 * @file IIndexBuilder.h
 * @brief Defines the IIndexBuilder interface for building and managing document indices.
 */

/**
 * @class IIndexBuilder
 * @brief Interface for building and managing document indices.
 * 
 * The IIndexBuilder interface provides methods for constructing indices for documents,
 * removing document indices, and retrieving the built index.
 */
class IIndexBuilder : public Object {
public:
    /**
     * @brief Virtual destructor for the IIndexBuilder interface.
     */
    virtual ~IIndexBuilder() = default;

    /**
     * @brief Builds an index for a document.
     * 
     * @param document The document to be indexed.
     */
    virtual void buildIndex(const Document& document) = 0;

    /**
     * @brief Removes the index of a document.
     * 
     * @param document The document whose index is to be removed.
     */
    virtual void removeIndex(const Document& document) = 0;

    /**
     * @brief Retrieves the built index.
     * 
     * @return A shared pointer to the IIndex object representing the built index.
     */
    virtual std::shared_ptr<IIndex> index() const = 0;
};

#endif