#ifndef _CATEGORY_H_
#define _CTEGORY_H_

#include <iostream>
#include <string>
#include <unordered_map>

#include "document.h"


class Category {
public:
    std::string categoryName;
    std::string get_caltegoryId();
    
    Category() = default; 
    Category(const std::string& id, const std::string& name) : _categoryId(id), categoryName(name) {}
    
    void setCategoryId(const std::string& id);
    void addDocument(const Document& doc);
    bool removeDocument(const std::string& docId);
    void printDocuments() const;

    friend class University;

private:
    std::string _categoryId;
    std::unordered_map<std::string, Document> _documents;
};

#endif