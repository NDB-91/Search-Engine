#ifndef _TRIE_H_
#define _TRIE_H_

#include <string>

struct TrieNode {
    TrieNode* childrens[26];
    bool endOfWord;

    TrieNode();
};

class Trie {
public:
    Trie();
    ~Trie();

    void insert(const std::string& word);
    bool search(const std::string& word);
    void remove(const std::string& word);
    bool startsWith(const std::string& prefix);
private:
    TrieNode* root;
};


#endif