#include "Document.h"

Document::Document(const std::string& id, DocumentType type, const std::string& title, const std::string& author)
    : _id(id), _type(type), _title(title), _author(author) {}

std::string Document::id() const {
    return _id;
}

DocumentType Document::type() const {
    return _type;
}

std::string Document::title() const {
    return _title;
}

std::string Document::author() const {
    return _author;
}