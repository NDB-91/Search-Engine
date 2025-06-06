#ifndef _DOCUMENT_MANAGER_H_
#define _DOCUMENT_MANAGER_H_

#include <fstream>
#include <vector>
#include <unordered_map>

#include "../Object.h"
#include "Document.h"

#define DOCUMENTS "database/document/documents.txt"

/**
 * @file DocumentManager.h
 * @brief Defines the DocumentManager class for managing a collection of documents.
 */

/**
 * @class DocumentManager
 * @brief Singleton class for managing documents in the system.
 * 
 * The DocumentManager class provides methods to add, retrieve, and manage documents.
 * It ensures that documents are loaded from and saved to a persistent storage.
 */
class DocumentManager : public Object {
public:
    /**
     * @brief Gets the singleton instance of the DocumentManager.
     * @return A reference to the DocumentManager instance.
     */
    static DocumentManager& instance();

    /**
     * @brief Adds a new document to the collection.
     * 
     * @param id The unique identifier of the document.
     * @param department The department associated with the document.
     * @param title The title of the document.
     * @param idAuthor The unique identifier of the author.
     */
    void addDocument(const Document& document);

    /**
     * @brief Retrieves a Document object by their id.
     * 
     * @param id The id of the Document.
     * @return A Document object.
     */
    Document getDocument(const std::string& id);

    /**
     * @brief Retrieves all documents in the collection.
     * @return A vector of shared pointers to Document objects.
     */
    std::vector<Document> documents() const;

    /**
     * @brief Deleted copy constructor to enforce singleton pattern.
     */
    DocumentManager(const DocumentManager&) = delete;

    /**
     * @brief Deleted copy assignment operator to enforce singleton pattern.
     */
    DocumentManager& operator=(const DocumentManager&) = delete;

private:
    /**
     * @brief Constructs a DocumentManager object.
     * 
     * This constructor is private to enforce the singleton pattern.
     */
    DocumentManager();

    /**
     * @brief Loads documents from persistent storage.
     */
    void loadDocuments();

    /**
     * @brief Saves a document to persistent storage.
     * 
     * @param id The unique identifier of the document.
     * @param department The department associated with the document.
     * @param title The title of the document.
     * @param idAuthor The unique identifier of the author.
     */
    void saveDocument(const Document& document);

    std::unordered_map<std::string, Document> _documents; /**< Collection of documents managed by the DocumentManager. */
};

#endif