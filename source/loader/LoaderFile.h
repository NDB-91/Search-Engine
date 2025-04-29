#ifndef _LOADER_FILE_H_
#define _LOADER_FILE_H_

#include <fstream>
#include <unordered_map>

#include "ILoader.h"

#define DOCS_PATH "../database/reference/"

class LoaderFile : public ILoader {
public:
    static LoaderFile& instance();
    
    ~LoaderFile() override = default;

    std::string loadDocument(const std::string& documentId) override;
private:
    LoaderFile() = default;

    std::unordered_map<std::string, std::string> _loadedDocuments;
};

#endif