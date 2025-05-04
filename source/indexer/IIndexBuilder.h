#ifndef _IINDEX_BUILDER_H_
#define _IINDEX_BUILDER_H_

#include <memory>
#include <string>

#include "IIndex.h"
#include "../document/Document.h"

class IIndexBuilder {
public:
    virtual ~IIndexBuilder() = default;
    virtual void buildIndex(const Document& document) = 0;
    virtual void removeIndex(const Document& document) = 0;
    virtual std::shared_ptr<IIndex> index() const = 0;
};

#endif