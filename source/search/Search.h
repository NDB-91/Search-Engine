#ifndef _SEARCH_H_
#define _SEARCH_H_

#include "SearchBase.h"

#define DIRECTORY_PATH "database/reference/"

class Search : public SearchBase {
public:
    Search() = default;
    ~Search() override = default;

    std::vector<std::string> search(const std::string& query) override;
};

#endif