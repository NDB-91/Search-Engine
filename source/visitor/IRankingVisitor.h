#ifndef _IRANKING_VISITOR_H_
#define _IRANKING_VISITOR_H_

#include "IVisitor.h"

class SearchEngine;

class IRankingVisitor : public IVisitor {
public:
    virtual ~IRankingVisitor() = default;
    
    /**
     * @brief Visits a SearchEngine object.
     * 
     * @param searchEngine The SearchEngine object to visit.
     */
    virtual void visit(std::shared_ptr<SearchEngine> searchEngine) = 0;

};

#include "../search/SearchEngine.h"

#endif