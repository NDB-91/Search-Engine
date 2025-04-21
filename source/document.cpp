#include "document.h"

Document::Document() {
    title = "UnknownTitle";
    uploader = "UnknownUploader";
    _documentId = "";
    filePath = "unknown/path";
    uploadDate = "";
}

Document::Document( std::string docID,std::string title1, std::string uploader1, std::string path, std::string cate, std::string auth, std::string date) {
    _documentId = docID;
    title = title1;
    uploader = uploader1;
    filePath = path;
    category = cate;
    author = auth;
    uploadDate = date;
}

Document::~Document() {}

std::string Document::get_documentID() const {
    return _documentId;
}

std::string Document::getFilePath() const {
     return filePath;
}

void Document::printDetails() const {
    std::cout << "Document ID: " << _documentId << "\nTitle: " << title << "\nUploader: " << uploader << std::endl;
}
