#include "category.h"

void Category::setCategoryId(const std::string& id) {
    _categoryId = id;
}

void Category::addDocument(const Document& doc) {
    std::string docID = doc.get_documentID();
    _documents[docID] = doc;
    std::cout << "Document \"" << docID << "\" added to category \"" << categoryName << "\".\n";
}

bool Category::removeDocument(const std::string& docId) {
    auto it = _documents.find(docId);
    if (it != _documents.end()) {
        _documents.erase(it);
        std::cout << "Document \"" << docId << "\" removed from category \"" << categoryName << "\".\n";
        return true;
    } else {
        std::cout << "Document \"" << docId << "\" not found in category.\n";
        return false;
    }
}

void Category::printDocuments() const {
    std::cout << "Documents in category \"" << categoryName << "\":\n";
    for (const auto& pair : _documents) {
        pair.second.printDetails();
    }
}
