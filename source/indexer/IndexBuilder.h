#ifndef _INDEX_BUILDER_H_
#define _INDEX_BUILDER_H_

#include <memory>
#include <vector>

#include "IIndex.h"

class IndexBuilder {
public:
    IndexBuilder();
    ~IndexBuilder() = default;

    void buildIndex(const std::string& documentId, const std::string& content);
    void removeIndex(const std::string& documentId);
    std::vector<std::string> search(const std::string& query);
private:
    std::shared_ptr<IIndex> _index;
};

#endif