#ifndef _TRIE_H_
#define _TRIE_H_

#include <string>

/**
 * @file Trie.h
 * @brief Defines the Trie and TrieNode classes for managing a prefix tree (trie) data structure.
 */

/**
 * @struct TrieNode
 * @brief Represents a node in the Trie data structure.
 * 
 * Each TrieNode contains an array of pointers to its child nodes and a flag indicating
 * whether the node marks the end of a word.
 */
struct TrieNode {
    TrieNode* childrens[26]; /**< Array of pointers to child nodes, one for each letter of the alphabet. */
    bool endOfWord;          /**< Flag indicating whether this node marks the end of a word. */

    /**
     * @brief Constructs a TrieNode object.
     */
    TrieNode();
};

/**
 * @class Trie
 * @brief Implements a prefix tree (trie) for efficient string storage and retrieval.
 * 
 * The Trie class provides methods to insert words, search for words, remove words,
 * and check for prefixes in the trie.
 */
class Trie {
public:
    /**
     * @brief Constructs a Trie object.
     */
    Trie();

    /**
     * @brief Destroys the Trie object and deallocates its nodes.
     */
    ~Trie();

    /**
     * @brief Inserts a word into the trie.
     * 
     * @param word The word to be inserted.
     */
    void insert(const std::string& word);

    /**
     * @brief Searches for a word in the trie.
     * 
     * @param word The word to search for.
     * @return True if the word exists in the trie, false otherwise.
     */
    bool search(const std::string& word);

    /**
     * @brief Removes a word from the trie.
     * 
     * @param word The word to be removed.
     */
    void remove(const std::string& word);

    /**
     * @brief Checks if any word in the trie starts with the given prefix.
     * 
     * @param prefix The prefix to check for.
     * @return True if any word starts with the prefix, false otherwise.
     */
    bool startsWith(const std::string& prefix);

private:
    TrieNode* root; /**< Pointer to the root node of the trie. */
};

#endif