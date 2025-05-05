#ifndef _DOCUMENT_H_
#define _DOCUMENT_H_

#include <string>

#include "../department/Department.h"
#include "../lecturer/Lecturer.h"

class Document {
public:
    Document(const std::string& id, const Department& department, const std::string& title, const std::string& _idAuthor);
    virtual ~Document() = default;

    std::string id() const;
    Department department() const;
    std::string title() const;
    std::string author() const;

    virtual std::string content() const;
protected:
    std::string _id;
    Department _department;
    std::string _title;
    std::string _idAuthor;
};

#endif