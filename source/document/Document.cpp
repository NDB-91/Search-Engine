#include "Document.h"
#include "../loader/LoaderFile.h"
#include "../lecturer/LecturerManager.h"

Document::Document()
    : _id(""), _department(Department::Unknown), _title(""), _idAuthor("") {}

Document::Document(const std::string& id, const Department& department, const std::string& title, const std::string& idAuthor)
    : _id(id), _department(department), _title(title), _idAuthor(idAuthor) {}

std::string Document::id() const {
    return _id;
}

Department Document::department() const {
    return _department;
}

std::string Document::title() const {
    return _title;
}

std::string Document::author() const {
    return LecturerManager::instance().getLecturerName(_idAuthor);
}

std::string Document::content() const {
    return LoaderFile::instance().loadDocument(_id);
}