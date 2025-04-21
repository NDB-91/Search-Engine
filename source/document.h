#ifndef _DOCUMENT_H_
#define _DOCUMENT_H_

#include <iostream>
#include <string>
#include <unordered_map>


class Document {
public:
    std::string title;
    std::string description;
    std::string uploader;
    //std::string faculty;
    std::string category;
    std::string author;
    std::string uploadDate;
    
    Document();
    Document( std::string docID, std::string title1, std::string uploader1, std::string path, std::string cate, std::string author, std::string date);
    ~Document();
    
    Document(Document& d, std::string newID);
    
    std::string get_documentID() const;
    std::string getFilePath() const;
    
    void printDetails() const;
    
    friend class University;
    friend class Category;
    friend class Author;

private:
    std::string _documentId;
    std::string filePath;
    
};

#endif 