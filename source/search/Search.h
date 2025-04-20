#ifndef _SEARCH_H_
#define _SEARCH_H_

#include "ISearch.h"

#include "../indexer/IndexManager.h"

#define DIRECTORY_PATH "references/"

class Search : public ISearch {
public:
    Search();
    ~Search() override;

    std::vector<std::string> search(const std::string& query) override;
private:
    IndexManager* _indexManager;
};

#endif