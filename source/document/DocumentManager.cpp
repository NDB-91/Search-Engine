#include "DocumentManager.h"
#include "Document.h"
#include "../lecturer/LecturerManager.h"
#include "../Utils.h"

DocumentManager& DocumentManager::instance() {
    static DocumentManager _instance;
    return _instance;
}

void DocumentManager::addDocument(const std::string& id, const Department& department, const std::string& title, const std::string& author) {
    std::shared_ptr<Document> doc(new Document(id, department, title, author));
    _documents.emplace_back(doc);
}

std::vector<std::shared_ptr<Document>> DocumentManager::documents() const {
    return _documents;
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
        addDocument(id, dept, title, author);
    }
    docsFile.close();
}

void DocumentManager::saveDocument(const std::string& id, const Department& department, const std::string& title, const std::string& author) {
    std::ofstream docsFile(DOCUMENTS, std::ios::app);
    if(!docsFile.is_open()) {
        throw std::runtime_error("Could not open documents file for writing");
        return;
    }
    docsFile << id << "|" << toString(department) << "|" << title << "|" << author << "\n";
    docsFile.close();
}

DocumentManager::DocumentManager() {
    loadDocuments();
}