#ifndef _INDEX_BUILDER_H_
#define _INDEX_BUILDER_H_

#include <vector>

#include "IIndexBuilder.h"
#include "InvertedIndex.h"

/**
 * @file InvertedIndexBuilder.h
 * @brief Defines the InvertedIndexBuilder class for constructing inverted indices.
 */

/**
 * @class InvertedIndexBuilder
 * @brief Implements the IIndexBuilder interface to build and manage inverted indices.
 * 
 * The InvertedIndexBuilder class provides methods to construct an inverted index for documents,
 * remove document indices, and retrieve the built inverted index.
 */
class InvertedIndexBuilder : public IIndexBuilder {
public:
    /**
     * @brief Constructs an InvertedIndexBuilder object.
     */
    InvertedIndexBuilder();

    /**
     * @brief Destroys the InvertedIndexBuilder object.
     */
    ~InvertedIndexBuilder() = default;

    /**
     * @brief Builds an index for a document.
     * 
     * @param document The document to be indexed.
     */
    void buildIndex(const Document& document) override;

    /**
     * @brief Removes the index of a document.
     * 
     * @param document The document whose index is to be removed.
     */
    void removeIndex(const Document& document) override;

    /**
     * @brief Retrieves the built inverted index.
     * 
     * @return A shared pointer to the IIndex object representing the built inverted index.
     */
    std::shared_ptr<IIndex> index() const override;

private:
    /**
     * @brief The inverted index being built and managed.
     */
    std::shared_ptr<InvertedIndex> _index;
};

#endif