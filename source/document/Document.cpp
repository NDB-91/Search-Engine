#include "Document.h"

Document::Document(const std::string& id, const Department& department, const std::string& title, const std::string& author)
    : DocumentBase(id, department, title, author) {}