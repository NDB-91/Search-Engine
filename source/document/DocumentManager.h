#ifndef _DOCUMENT_MANAGER_H_
#define _DOCUMENT_MANAGER_H_

#include <vector>

#include "IDocument.h"
#include "../indexer/IndexManager.h"
#include "../loader/ILoader.h"

class DocumentManager {
public:
    DocumentManager();
    ~DocumentManager();

    void addDocument(const std::string& id, DocumentType type, const std::string& title, const std::string& author);
private:
    std::vector<IDocument*> _documents;
    IndexManager* _indexManager;
    ILoader* _loader;
};

#endif