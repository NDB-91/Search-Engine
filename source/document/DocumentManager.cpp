#include "DocumentManager.h"
#include "Document.h"

DocumentManager::DocumentManager() {

}

DocumentManager::~DocumentManager() {
    for (DocumentBase* doc : _documents) {
        delete doc;
    }
}

void DocumentManager::addDocument(const std::string& id, const Department& department, const std::string& title, const std::string& author) {
    DocumentBase* doc = new Document(id, department, title, author);
    _documents.push_back(doc);
}