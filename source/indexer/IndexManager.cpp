#include <iostream>
#include <filesystem>

#include "IndexManager.h"
#include "../loader/LoaderFile.h"

IndexManager& IndexManager::instance() {
    static IndexManager _instance;
    return _instance;
}

void IndexManager::addDocument(const std::string& documentId) {
    std::string content = LoaderFile::instance().loadDocument(_directoryPath + documentId);
    _indexBuilder->buildIndex(documentId, content);
}

void IndexManager::removeDocument(const std::string& documentId) {
    
}

void IndexManager::buildIndexDirectory(const std::string& directoryPath) {
    _directoryPath = directoryPath;
    for(const auto& entry : std::filesystem::directory_iterator(_directoryPath)) {
        if(entry.is_regular_file() && entry.path().extension() == ".txt") {
            std::string documentID = entry.path().filename().string();
            if(_indexed.find(documentID) != _indexed.end()) {
                continue;
            }
            _indexed.insert(documentID);
            addDocument(documentID);
            std::cout << "Indexed document: " << documentID << "\n";
        }
    }
}

std::vector<std::string> IndexManager::search(const std::string& query) {
    return _indexBuilder->search(query);
}

IndexManager::IndexManager() {
    _indexBuilder = std::make_shared<IndexBuilder>();
}