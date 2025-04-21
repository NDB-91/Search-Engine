#include "author.h"

Author::Author() {
    _authorId = "UnknownID";
    _authorEmail = "UnknownEmail";
    authorName = "UnknownName";
    authorBio = "No biography available.";
}

Author::Author(std::string id, std::string email, std::string name, std::string bio) {
    _authorId = id;
    _authorEmail = email;
    authorName = name;
    authorBio = bio;
}

Author::~Author(){}

std::string Author::getAuthorId() const {
    return _authorId;
}

std::string Author::getAuthorEmail() const {
    return _authorEmail;
}

void Author::setAuthorId(const std::string& id) {
    _authorId = id;
}

void Author::setAuthorEmail(const std::string& email) {
    _authorEmail = email;
}

void Author::addDocument(const Document& doc) {
    listDocument[doc.get_documentID()] = doc;
}

void Author::printInfo() const {
    std::cout << "Author ID: " << _authorId << std::endl;
    std::cout << "Author Name: " << authorName << std::endl;
    std::cout << "Author Email: " << _authorEmail << std::endl;
    std::cout << "Author Bio: " << authorBio << std::endl;
}
