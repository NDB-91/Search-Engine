#ifndef _ILOADER_H_
#define _ILOADER_H_

#include <string>

class ILoader {
public:
    ILoader() = default;
    virtual ~ILoader() = default;

    virtual std::string loadDocument(const std::string& documentId) = 0;
};

#endif