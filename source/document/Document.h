#ifndef _DOCUMENT_H_
#define _DOCUMENT_H_

#include "DocumentBase.h"

class Document : public DocumentBase {
public:
    Document(const std::string& id, const Department& department, const std::string& title, const std::string& author);
};

#endif