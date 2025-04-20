#ifndef _LOADER_FILE_H_
#define _LOADER_FILE_H_

#include <fstream>
#include <unordered_map>

#include "ILoader.h"

class LoaderFile : public ILoader {
public:
    LoaderFile() = default;
    ~LoaderFile() override = default;

    std::string loadDocument(const std::string& documentId) override;
private:
    std::unordered_map<std::string, std::string> _loadedDocuments;
};

#endif