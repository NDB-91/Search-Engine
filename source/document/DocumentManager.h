#ifndef _DOCUMENT_MANAGER_H_
#define _DOCUMENT_MANAGER_H_

#include <vector>

#include "DocumentBase.h"

class DocumentManager {
public:
    DocumentManager();
    ~DocumentManager();

    void addDocument(const std::string& id, const Department& department, const std::string& title, const std::string& author);
private:
    std::vector<DocumentBase*> _documents;
};

#endif