#include <iostream>
#include <format>

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

std::string DocumentBase::author() const {
    return _author;
}

void DocumentBase::preview() const {
    std::cout << "------------------------\n";
    std::cout << std::format("Document ID: {}\n", _id);
    std::cout << std::format("Department: {}\n", _department);
    std::cout << std::format("Title: {}\n", _title);
    std::cout << std::format("Author: {}\n", _author);
    std::cout << "------------------------\n";
}