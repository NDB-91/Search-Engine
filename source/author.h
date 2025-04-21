#ifndef _AUTHOR_H_
#define _AUTHOR_H_

#include <iostream>
#include <string>
#include <unordered_map>

#include "document.h"

class Author {
public:
    std::string authorName;
    std::string authorBio;

    Author();
    Author(std::string id, std::string email, std::string name, std::string bio);
    ~Author();

    std::string getAuthorId() const;
    std::string getAuthorEmail() const;
    void setAuthorId(const std::string& id);
    void setAuthorEmail(const std::string& email);

    void addDocument(const Document& doc);

    void printInfo() const;

    friend class University;

private:
    std::string _authorId;
    std::string _authorEmail;
    std::unordered_map<std::string, Document> listDocument;

};

#endif