#ifndef _DOCUMENT_MANAGER_H_
#define _DOCUMENT_MANAGER_H_

#include <fstream>
#include <memory>
#include <vector>

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
class DocumentManager {
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
    void addDocument(const std::string& id, const Department& department, const std::string& title, const std::string& idAuthor);

    /**
     * @brief Retrieves all documents in the collection.
     * @return A vector of shared pointers to Document objects.
     */
    std::vector<std::shared_ptr<Document>> documents() const;

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
    void saveDocument(const std::string& id, const Department& department, const std::string& title, const std::string& idAuthor);

    std::vector<std::shared_ptr<Document>> _documents; /**< Collection of documents managed by the DocumentManager. */
};

#endif