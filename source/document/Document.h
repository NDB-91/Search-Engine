#ifndef _DOCUMENT_H_
#define _DOCUMENT_H_

#include <string>

#include "../Object.h"
#include "../department/Department.h"
#include "../lecturer/Lecturer.h"

/**
 * @file Document.h
 * @brief Defines the Document class for managing documents in the system.
 */

/**
 * @class Document
 * @brief Represents a document associated with a specific department and author.
 * 
 * The Document class provides methods to access document metadata such as ID, department, title, author, and content.
 */
class Document : public Object {
public:
    /**
     * @brief Default constructor for the Document class.
     */
    Document();

    /**
     * @brief Constructs a Document object.
     * 
     * @param id The unique identifier of the document.
     * @param department The department associated with the document.
     * @param title The title of the document.
     * @param _idAuthor The unique identifier of the author.
     */
    Document(const std::string& id, const Department& department, const std::string& title, const std::string& _idAuthor);

    /**
     * @brief Virtual destructor for the Document class.
     */
    virtual ~Document() = default;

    /**
     * @brief Gets the unique identifier of the document.
     * @return The document ID as a string.
     */
    std::string id() const;

    /**
     * @brief Gets the department associated with the document.
     * @return The department as a Department enumeration value.
     */
    Department department() const;

    /**
     * @brief Gets the title of the document.
     * @return The title as a string.
     */
    std::string title() const;

    /**
     * @brief Gets the unique identifier of the author of the document.
     * @return The author ID as a string.
     */
    std::string author() const;

    /**
     * @brief Gets the content of the document.
     * @return The content as a string.
     */
    virtual std::string content() const;
protected:
    std::string _id;           /**< The unique identifier of the document. */
    Department _department;    /**< The department associated with the document. */
    std::string _title;        /**< The title of the document. */
    std::string _idAuthor;     /**< The unique identifier of the author. */
};

#endif