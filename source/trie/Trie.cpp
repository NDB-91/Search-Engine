#include <functional>

#include "Trie.h"

TrieNode::TrieNode() {
    for(int i = 0; i < 26; ++i){
        childrens[i] = nullptr;
    }
    endOfWord = false;
    frequency = 0;
}

Trie::Trie() {
    _root = new TrieNode();
}

Trie::~Trie() {
    std::function<void(TrieNode*)> deleteNode = [&](TrieNode* node) {
        if (node) {
            for (int i = 0; i < 26; ++i) {
                deleteNode(node->childrens[i]);
            }
            delete node;
        }
    };
    deleteNode(_root);
}

TrieNode* Trie::getRoot() const {
    return _root;
}

void Trie::insert(const std::string& word) {
    TrieNode* current = _root;
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
    TrieNode* current = _root;
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
    TrieNode* current = _root;
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
    TrieNode* current = _root;
    for(char c : prefix) {
        int index = c - 'a';
        if(current->childrens[index] == nullptr) {
            return false;
        }
        current = current->childrens[index];
    }
    return true;
}

int Trie::getFrequency(const std::string& word) {
    TrieNode* current = _root;
    for(char c : word) {
        int index = c - 'a';
        if(current->childrens[index] == nullptr) {
            return 0; // Word not found
        }
        current = current->childrens[index];
    }
    return current->endOfWord ? 1 : 0; // Return 1 if the word exists, otherwise 0
}