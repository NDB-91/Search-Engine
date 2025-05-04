#ifndef _INDEX_SEARCHER_H_
#define _INDEX_SEARCHER_H_

#include <memory>
#include <string>
#include <vector>
#include "../indexer/IIndex.h"
#include "../indexer/IIndexBuilder.h"

class IndexSearcher {
public:
    IndexSearcher();
    explicit IndexSearcher(const std::shared_ptr<IIndexBuilder>& indexBuilder);
    std::vector<std::string> search(const std::string& query) const;
private:
    std::shared_ptr<IIndex> _index;
};

#endif