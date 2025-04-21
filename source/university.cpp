#include "university.h"

University::University(const std::string& id, const std::string& name, const std::string& address, const std::string& email) {
    _universityId = id;
    universityName = name;
    universityAddress = address;
    universityEmail = email;

    _doc_ids = std::vector<std::string>();
    _member_ids = std::vector<std::string>();
    _documents = std::unordered_map<std::string, Document>();
    _members = std::unordered_map<std::string, Member>();
    _categories = std::unordered_map<std::string, Category>();
    _authors = std::unordered_map<std::string, Author>();
}

University::~University() {}


void University::addMember(const Member& m) {
    _members[m._memberID] = m;
}

void University::addAuthor(const Author& a) {
    _authors[a.getAuthorId()] = a;
}

void University::addCategory(const Category& c) {
    _categories[c.categoryName] = c;
}

Category& University::getCategory(const std::string& categoryName) {
    auto it = _categories.find(categoryName);
    if (it != _categories.end()) {
        return it->second;
    } else {
        Category newCategory;
        newCategory.categoryName = categoryName;
        _categories[categoryName] = newCategory;
        return _categories[categoryName];
    }
}

Author& University::getAuthor(const std::string& authorId) {
    auto it = _authors.find(authorId);
    if (it != _authors.end()) {
        return it->second;
    } else {
        Author newAuthor;
        _authors[authorId] = newAuthor;
        return _authors[authorId];
    }
}

bool University::addDocument(const Member& member, const Document& d){
    if (member.role != "lecturer" && member.role != "admin") {
        std::cout << "Permission denied: Only lecturers and admins can add documents.\n";
        return false;
    }
    std::string doc_id1 = d.get_documentID();
    auto itr1 = _documents.find(doc_id1);
    if (itr1 == _documents.end()) {
        _documents[doc_id1] = d;
        _doc_ids.push_back(doc_id1);

        Category& category = getCategory(d.category);
        category.addDocument(d);

        Author& author = getAuthor(d.author);
        author.addDocument(d);
    } else {
       std::cout << "The request is invalid! A document with the same documentID already exists." << std::endl;
       return false;
    }
    return true;
}

bool University::downloadDocument(const std::string& member_id, const std::string& doc_id) const {
    auto it = _documents.find(doc_id);
    if (it == _documents.end()) {
        std::cout << "Document with ID \"" << doc_id << "\" not found.\n";
        return false;
    }

    std::string sourcePath = it->second.getFilePath();
    std::string destPath = "downloads/" + member_id + "_" + doc_id + ".txt";

    std::ifstream src(sourcePath, std::ios::binary);
    if (!src.is_open()) {
        std::cout << "Cannot open source file: " << sourcePath << "\n";
        return false;
    }

    std::ofstream dest(destPath, std::ios::binary);
    if (!dest.is_open()) {
        std::cout << "Cannot create destination file: " << destPath << "\n";
        return false;
    }

    dest << src.rdbuf();

    std::cout << "Downloaded: " << doc_id << " for member " << member_id << " -> " << destPath << "\n";
    return true;
}

void University::printDocument(const std::string& docID) {
    auto it = _documents.find(docID);
    if (it != _documents.end()) {
        it->second.printDetails();
    } else {
        std::cout << "Document not found.\n";
    }
}

void University::printMember(const std::string& memberID) {
    auto it = _members.find(memberID);
    if (it != _members.end()) {
        it->second.printDetails();
    } else {
        std::cout << "Member not found.\n";
    }
}

void University::printAuthorInfo(const std::string& authorID) const {
    auto it = _authors.find(authorID);
    if (it != _authors.end()) {
        it->second.printInfo();
    } else {
        std::cout << "Author not found.\n";
    }
}

void University::printUniversityDetails() {
    std::cout << "University Name: " << universityName << "\n";
    std::cout << "University Address: " << universityAddress << "\n";
    std::cout << "University Email: " << universityEmail << "\n";
}
