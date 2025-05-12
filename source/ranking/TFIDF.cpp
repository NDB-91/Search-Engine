#include "TFIDF.h"
#include "../document/DocumentManager.h"
#include "../text/TextProcessor.h"

TFIDF& TFIDF::instance() {
    static TFIDF _instance;
    return _instance;
}

float TFIDF::calculateTF(const Document& document, const std::string& term) const {
    std::string content = document.content();
    content = TextProcessor::toLower(content);
    std::vector<std::string> words = TextProcessor::tokenize(content);
    int totalWords = words.size();
    int termCount = 0;
    std::istringstream iss(content);
    std::string word;
    while (iss >> word) {
        if (word == term) {
            termCount++;
        }
    }
    return static_cast<float>(termCount) / totalWords;
}

float TFIDF::calculateIDF(const std::string& term) const {
    std::vector<Document> documents = DocumentManager::instance().documents();
    int totalDocuments = documents.size();
    int termDocumentCount = 0;
    for(const auto& doc : documents) {
        std::string content = doc.content();
        content = TextProcessor::toLower(content);
        std::vector<std::string> words = TextProcessor::tokenize(content);
        if (std::find(words.begin(), words.end(), term) != words.end()) {
            termDocumentCount++;
        }
    }
    return std::log(static_cast<float>(totalDocuments) / termDocumentCount);
}

float TFIDF::calculateTFIDF(const Document& document, const std::string& term) const {
    return calculateTF(document, term) * calculateIDF(term);
}