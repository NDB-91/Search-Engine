#ifndef _INDEX_BUILDER_H_
#define _INDEX_BUILDER_H_

#include <vector>

#include "IIndexBuilder.h"
#include "InvertedIndex.h"

class InvertedIndexBuilder : public IIndexBuilder {
public:
    InvertedIndexBuilder();
    ~InvertedIndexBuilder() = default;

    void buildIndex(const Document& document) override;
    void removeIndex(const Document& document) override;
    std::shared_ptr<IIndex> index() const override;
private:
    std::shared_ptr<InvertedIndex> _index;
};

#endif