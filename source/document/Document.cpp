#include "Document.h"
#include "../loader/LoaderFile.h"

Document::Document(const std::string& id, const Department& department, const std::string& title, const Lecturer& author)
    : _id(id), _department(department), _title(title), _author(author) {}

std::string Document::id() const {
    return _id;
}

Department Document::department() const {
    return _department;
}

std::string Document::title() const {
    return _title;
}

Lecturer Document::author() const {
    return _author;
}

std::string Document::content() const {
    return LoaderFile::instance().loadDocument(_id);
}