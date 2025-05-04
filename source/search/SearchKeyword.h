#ifndef _SEARCH_KEYWORD_H_
#define _SEARCH_KEYWORD_H_

#include "SearchBase.h"

#define DIRECTORY_PATH "database/reference/"

class SearchKeyword : public SearchBase {
public:
    SearchKeyword();
    ~SearchKeyword() override = default;

    std::vector<std::string> search(const std::string& query) override;
};

#endif