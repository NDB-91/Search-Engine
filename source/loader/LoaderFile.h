#ifndef _LOADER_FILE_H_
#define _LOADER_FILE_H_

#include <fstream>
#include <unordered_map>

#include "ILoader.h"

#define DOCS_PATH "database/reference/"

/**
 * @file LoaderFile.h
 * @brief Defines the LoaderFile class for loading document content from files.
 */

/**
 * @class LoaderFile
 * @brief Singleton class for loading document content from files.
 * 
 * The LoaderFile class implements the ILoader interface and provides functionality
 * to load document content from files stored in a specified directory. It uses a
 * singleton pattern to ensure a single instance of the loader.
 */
class LoaderFile : public ILoader {
public:
    /**
     * @brief Gets the singleton instance of the LoaderFile.
     * @return A reference to the LoaderFile instance.
     */
    static LoaderFile& instance();
    
    /**
     * @brief Destroys the LoaderFile object.
     */
    ~LoaderFile() override = default;

    /**
     * @brief Loads the content of a document from a file.
     * 
     * @param documentId The unique identifier of the document to be loaded.
     * @return The content of the document as a string.
     */
    std::string loadDocument(const std::string& documentId) override;

private:
    /**
     * @brief Constructs a LoaderFile object.
     * 
     * This constructor is private to enforce the singleton pattern.
     */
    LoaderFile() = default;

    /**
     * @brief A cache of loaded documents.
     * 
     * Maps document IDs to their content to avoid reloading the same document multiple times.
     */
    std::unordered_map<std::string, std::string> _loadedDocuments;
};

#endif