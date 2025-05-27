#ifndef _ILOADER_H_
#define _ILOADER_H_

#include <string>

#include "../Object.h"

/**
 * @file ILoader.h
 * @brief Defines the ILoader interface for loading document content.
 */

/**
 * @class ILoader
 * @brief Interface for loading document content by document ID.
 * 
 * The ILoader interface provides a method to load the content of a document
 * based on its unique identifier.
 */
class ILoader : public Object {
public:
    /**
     * @brief Virtual destructor for the ILoader interface.
     */
    virtual ~ILoader() = default;

    /**
     * @brief Loads the content of a document.
     * 
     * @param documentId The unique identifier of the document to be loaded.
     * @return The content of the document as a string.
     */
    virtual std::string loadDocument(const std::string& documentId) = 0;
};

#endif