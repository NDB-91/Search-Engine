#ifndef _ISEARCH_H_
#define _ISEARCH_H_

#include <vector>
#include <string>

class ISearch {
public:
    ISearch() = default;
    virtual ~ISearch() = default;

    virtual std::vector<std::string> search(const std::string& query) = 0;
};

#endif