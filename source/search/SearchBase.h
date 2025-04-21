#ifndef _SEARCH_BASE_H_
#define _SEARCH_BASE_H_

#include <vector>
#include <string>

class SearchBase {
public:
    SearchBase() = default;
    virtual ~SearchBase() = default;

    virtual std::vector<std::string> search(const std::string& query) = 0;
};

#endif