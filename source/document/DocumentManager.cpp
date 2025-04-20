#include "DocumentManager.h"
#include "Document.h"

DocumentManager::DocumentManager() {
    _indexManager = new IndexManager();
    _loader = nullptr;
}

DocumentManager::~DocumentManager() {
    for (IDocument* doc : _documents) {
        delete doc;
    }
    delete _indexManager;
    if (_loader) {
        delete _loader;
    }
}

void DocumentManager::addDocument(const std::string& id, DocumentType type, const std::string& title, const std::string& author) {
    IDocument* doc = new Document(id, type, title, author);
    _documents.push_back(doc);
}