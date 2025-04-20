#ifndef _IDOCUMENT_H_
#define _IDOCUMENT_H_

#include <string>

enum DocumentType {
    MATHEMATICS,
    PHYSICS,
    CHEMISTRY,
    BIOLOGY,
    INFORMATION_TECHNOLOGY,
    LINGUISTICS,
    MAKETING,
    ECONOMICS,
    PHILOSOPHY,
};

class IDocument {
public:
    IDocument() = default;
    virtual ~IDocument() = default;

    virtual std::string id() const = 0;
    virtual DocumentType type() const = 0;
    virtual std::string title() const = 0;
    virtual std::string author() const = 0;
};

#endif