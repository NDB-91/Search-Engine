#include <sstream>

#include "LoaderFile.h"

LoaderFile& LoaderFile::instance() {
    static LoaderFile _instance;
    return _instance;
}

std::string LoaderFile::loadDocument(const std::string& documentId) {
    if (_loadedDocuments.find(documentId) != _loadedDocuments.end()) {
        return _loadedDocuments[documentId];
    }
    std::fstream file(documentId);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + documentId);
    }
    std::stringstream content;
    std::string line;
    while (std::getline(file, line)) {
        content << line << "\n";
    }
    file.close();
    _loadedDocuments[documentId] = content.str();
    return _loadedDocuments[documentId];
}