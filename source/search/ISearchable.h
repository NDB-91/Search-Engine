#ifndef _ISEARCHABLE_H_
#define _ISEARCHABLE_H_

#include <string>

class ISearchable {
public:
    ISearchable() = default;
    virtual ~ISearchable() = default;

    virtual void search(const std::string& query) = 0;
};

#endif