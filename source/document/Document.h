#ifndef _DOCUMENT_H_
#define _DOCUMENT_H_

#include <string>

#include "../department/Department.h"
#include "../lecturer/Lecturer.h"

class Document {
public:
    Document(const std::string& id, const Department& department, const std::string& title, const Lecturer& author);
    virtual ~Document() = default;

    std::string id() const;
    Department department() const;
    std::string title() const;
    Lecturer author() const;

    std::string content() const;
protected:
    std::string _id;
    Department _department;
    std::string _title;
    Lecturer _author;
};

#endif