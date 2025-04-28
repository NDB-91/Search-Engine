#ifndef _DOCUMENT_MANAGER_H_
#define _DOCUMENT_MANAGER_H_

#include <memory>
#include <vector>

#include "Document.h"

class DocumentManager {
public:
    static DocumentManager& instance();

    void addDocument(const std::string& id, const Department& department, const std::string& title, const Lecturer& author);
    std::vector<std::shared_ptr<Document>> documents() const;
private:
    DocumentManager() = default;

    std::vector<std::shared_ptr<Document>> _documents;
};

#endif