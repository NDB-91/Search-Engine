#include "DocumentManager.h"
#include "Document.h"
#include "../lecturer/LecturerManager.h"
#include "../Utils.h"

DocumentManager& DocumentManager::instance() {
    static DocumentManager _instance;
    return _instance;
}

void DocumentManager::addDocument(const Document& document) {
    saveDocument(document);
}

Document DocumentManager::getDocument(const std::string& id) {
    return _documents[id];
}

std::vector<Document> DocumentManager::documents() const {
    std::vector<Document> documents;
    for(const auto& pair : _documents) {
        documents.emplace_back(pair.second);
    }
    return documents;
}

void DocumentManager::loadDocuments() {
    std::ifstream docsFile(DOCUMENTS);
    if(!docsFile.is_open()) {
        throw std::runtime_error("Could not open documents file");
        return;
    }
    std::string id, department, title, author;
    std::string line;
    while (std::getline(docsFile, line)) {
        auto tokens = split(line, '|');
        if (tokens.size() != 4) {
            throw std::runtime_error("Invalid document format");
        }
        id = tokens[0];
        department = tokens[1];
        title = tokens[2];
        author = tokens[3];

        Department dept = convertDepartment(department);
        Document document(id, dept, title, author);
        _documents[id] = document;
    }
    docsFile.close();
}

void DocumentManager::saveDocument(const Document& document) {
    if(_documents.find(document.id()) != _documents.end()){
        return;
    }
    _documents[document.id()] = document;
    std::ofstream docsFile(DOCUMENTS, std::ios::app);
    if(!docsFile.is_open()) {
        throw std::runtime_error("Could not open documents file for writing");
        return;
    }
    docsFile << document.id() << "|"
                << toString(document.department()) << "|"
                << document.title() << "|"
                << document.author() << "\n";
    docsFile.close();
}

DocumentManager::DocumentManager() {
    loadDocuments();
}