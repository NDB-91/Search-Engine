#ifndef _DOCUMENT_BASE_H_
#define _DOCUMENT_BASE_H_

#include <string>

#include "../department/Department.h"

class DocumentBase {
public:
    DocumentBase(const std::string& id, const Department& department, const std::string& title, const std::string& author);
    virtual ~DocumentBase() = default;

    std::string id() const;
    Department department() const;
    std::string title() const;
    std::string author() const;

    virtual void preview() const;
protected:
    std::string _id;
    Department _department;
    std::string _title;
    std::string _author;
    std::string _university;
};

#endif