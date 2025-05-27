#ifndef _SEARCHSUGGESTER_H_
#define _SEARCHSUGGESTER_H_

#include <fstream>
#include <algorithm>

#include "ISuggester.h"
#include "../logger/SearchLogger.h"
#include "../trie/Trie.h"

/**
 * @file SearchSuggester.h
 * @brief Defines the SearchSuggester class for providing search suggestions.
 */

/**
 * @class SearchSuggester
 * @brief Implements the ISuggester interface to provide search suggestions.
 * 
 * The SearchSuggester class provides functionality for generating suggestions
 * based on user input or search history.
 */
class SearchSuggester : public ISuggester {
public:
    /**
     * @brief Constructs a SearchSuggester object and loads search history.
     */
    SearchSuggester();

    /**
     * @brief Destroys the SearchSuggester object.
     */
    ~SearchSuggester() override = default;

    /**
     * @brief Suggests queries that start with the given prefix.
     * 
     * @param prefix The prefix to search for.
     * @return A vector of suggested queries.
     */
    std::vector<std::string> suggest(const std::string& prefix) override;

private:
    Trie _trie; ///< The trie data structure for storing and searching queries.
    TrieNode* _trieRoot; ///< The root node of the trie.

    /**
     * @brief Loads search history from the log file into the trie.
     */
    void loadHistory();

    /**
     * @brief Gets the root node of the trie.
     * 
     * @return A pointer to the root TrieNode.
     */
    TrieNode* getTrieRoot();

    /**
     * @brief Recursively collects suggestions from the trie.
     * 
     * @param node The current TrieNode.
     * @param current The current suggestion being formed.
     * @param results The vector to store collected suggestions.
     */
    void collectSuggestions(TrieNode* node, std::string word, std::vector<std::string>& results);
};

#endif