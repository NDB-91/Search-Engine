#include "Trie.h"

TrieNode::TrieNode() {
    for(int i = 0; i < 26; ++i){
        childrens[i] = nullptr;
    }
    endOfWord = false;
}

Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    delete root;
}

void Trie::insert(const std::string& word) {
    TrieNode* current = root;
    for(char c : word) {
        int index = c - 'a';
        if(current->childrens[index] == nullptr) {
            current->childrens[index] = new TrieNode();
        }
        current = current->childrens[index];
    }
    current->endOfWord = true;
}

bool Trie::search(const std::string& word) {
    TrieNode* current = root;
    for(char c : word) {
        int index = c - 'a';
        if(current->childrens[index] == nullptr) {
            return false;
        }
        current = current->childrens[index];
    }
    return current->endOfWord;
}

void Trie::remove(const std::string& word) {
    TrieNode* current = root;
    for(char c : word) {
        int index = c - 'a';
        if(current->childrens[index] == nullptr) {
            return;
        }
        current = current->childrens[index];
    }
    if(current->endOfWord) {
        current->endOfWord = false;
    }
}

bool Trie::startsWith(const std::string& prefix) {
    TrieNode* current = root;
    for(char c : prefix) {
        int index = c - 'a';
        if(current->childrens[index] == nullptr) {
            return false;
        }
        current = current->childrens[index];
    }
    return true;
}