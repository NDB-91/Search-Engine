#ifndef _INVERTED_INDEX_H_
#define _INVERTED_INDEX_H_

#include <unordered_map>
#include <unordered_set>
#include <sstream>

#include "IIndex.h"

/**
 * @file InvertedIndex.h
 * @brief Defines the InvertedIndex class for managing an inverted index of documents.
 */

/**
 * @class InvertedIndex
 * @brief Implements the IIndex interface using an inverted index structure.
 * 
 * The InvertedIndex class provides methods to index documents, remove document indices,
 * and query the index for relevant documents based on a search query. It uses an
 * unordered map to store the mapping between terms and the set of document identifiers
 * containing those terms.
 */
class InvertedIndex : public IIndex {
public:
    /**
     * @brief Constructs an InvertedIndex object.
     */
    InvertedIndex() = default;

    /**
     * @brief Destroys the InvertedIndex object.
     */
    ~InvertedIndex() override = default;

    /**
     * @brief Indexes a document by adding its terms to the inverted index.
     * 
     * @param document The document to be indexed.
     */
    void indexDocument(const Document& document) override;

    /**
     * @brief Removes the index of a document by removing its terms from the inverted index.
     * 
     * @param document The document whose index is to be removed.
     */
    void removeIndex(const Document& document) override;

    /**
     * @brief Queries the inverted index for relevant documents based on a search query.
     * 
     * @param query The search query string.
     * @return A vector of document identifiers matching the query.
     */
    std::vector<std::string> search(const std::string& query) override;

private:
    /**
     * @brief The inverted index data structure.
     * 
     * Maps terms (strings) to a set of document identifiers (strings) that contain those terms.
     */
    std::unordered_map<std::string, std::unordered_set<std::string>> _indexs;
};

#endif