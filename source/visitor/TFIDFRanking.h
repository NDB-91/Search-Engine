#ifndef _TFIDF_RANKING_H_
#define _TFIDF_RANKING_H_

#include <algorithm>

#include "IRankingVisitor.h"
#include "../search/SearchEngine.h"

class TFIDFRanking : public IRankingVisitor {
public:
    /**
     * @brief Visits a SearchEngine object and performs TF-IDF ranking.
     * 
     * @param searchEngine The SearchEngine object to visit.
     */
    void visit(std::shared_ptr<SearchEngine> searchEngine) override;
};

#endif