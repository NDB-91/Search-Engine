#ifndef _DOCUMENT_H_
#define _DOCUMENT_H_

#include "IDocument.h"

class Document : public IDocument {
public:
    Document(const std::string& id, DocumentType type, const std::string& title, const std::string& author);
    
    std::string id() const override;
    DocumentType type() const override;
    std::string title() const override;
    std::string author() const override;
private:
    std::string _id;
    DocumentType _type;
    std::string _title;
    std::string _author;
};

#endif