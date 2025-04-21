#ifndef _UNIVERSITY_H_
#define _UNIVERSITY_H_

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <fstream>

#include "member.h"
#include "category.h"
#include "author.h"

class University {
public:
    std::string universityName;
    std::string universityAddress;
    std::string universityEmail;

    University(const std::string& id, const std::string& name, const std::string& address, const std::string& email);
    
    void addMember(const Member& m);
    void addAuthor(const Author& a);
    void addCategory(const Category& c);


    Category& getCategory(const std::string& categoryName);
    Author& getAuthor(const std::string& authorId);

    bool addDocument(const Member& member, const Document& d);

    bool downloadDocument(const std::string& member_id, const std::string& doc_id) const;

    void printDocument(const std::string& docID);
    void printMember(const std::string& memberID);
    void printUniversityDetails();
    void printAuthorInfo(const std::string& authorID) const;

private:
    std::string _universityId;
    std::vector<std::string> _doc_ids;
    std::vector<std::string> _member_ids;
    std::unordered_map<std::string, Document> _documents;
    std::unordered_map<std::string, Member> _members;
    std::unordered_map<std::string, Category> _categories;
    std::unordered_map<std::string, Author> _authors; 
};


#endif