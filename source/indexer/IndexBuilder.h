#ifndef _INDEX_BUILDER_H_
#define _INDEX_BUILDER_H_

#include <vector>

#include "IIndex.h"

class IndexBuilder {
public:
    IndexBuilder();
    ~IndexBuilder();

    void buildIndex(const std::string& documentId, const std::string& content);
    void removeIndex(const std::string& documentId);
    std::vector<std::string> search(const std::string& query);
private:
    IIndex* _index;
};

#endif