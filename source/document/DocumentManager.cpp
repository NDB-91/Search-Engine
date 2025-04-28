#include "DocumentManager.h"
#include "Document.h"

DocumentManager& DocumentManager::instance() {
    static DocumentManager _instance;
    return _instance;
}

void DocumentManager::addDocument(const std::string& id, const Department& department, const std::string& title, const Lecturer& author) {
    std::shared_ptr<Document> doc(new Document(id, department, title, author));
    _documents.emplace_back(doc);
}

std::vector<std::shared_ptr<Document>> DocumentManager::documents() const {
    return _documents;
}