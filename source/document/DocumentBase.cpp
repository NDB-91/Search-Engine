#include "DocumentBase.h"

DocumentBase::DocumentBase(const std::string& id, const Department& department, const std::string& title, const std::string& author)
    : _id(id), _department(department), _title(title), _author(author) {}

std::string DocumentBase::id() const {
    return _id;
}

Department DocumentBase::department() const {
    return _department;
}

std::string DocumentBase::title() const {
    return _title;
}