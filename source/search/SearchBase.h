#ifndef _SEARCH_BASE_H_
#define _SEARCH_BASE_H_

#include <memory>
#include <vector>
#include <string>

#include "../indexer/IIndexBuilder.h"
#include "IndexSearcher.h"

class SearchBase {
public:
    virtual ~SearchBase() = default;
    virtual std::vector<std::string> search(const std::string& query) = 0;
protected:
    std::shared_ptr<IIndexBuilder> _indexBuilder;
    IndexSearcher _indexSearcher;
};

#endif