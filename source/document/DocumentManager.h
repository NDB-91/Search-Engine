#ifndef _DOCUMENT_MANAGER_H_
#define _DOCUMENT_MANAGER_H_

#include <fstream>
#include <memory>
#include <vector>

#include "Document.h"

#define DOCUMENTS "documents.txt"

class DocumentManager {
public:
    static DocumentManager& instance();

    void addDocument(const std::string& id, const Department& department, const std::string& title, const std::string& idAuthor);
    std::vector<std::shared_ptr<Document>> documents() const;

    DocumentManager(const DocumentManager&) = delete;
    DocumentManager& operator=(const DocumentManager&) = delete;
private:
    DocumentManager() = default;
    void loadDocuments();
    void saveDocument(const std::string& id, const Department& department, const std::string& title, const std::string& idAuthor);

    std::vector<std::shared_ptr<Document>> _documents;
};

#endif