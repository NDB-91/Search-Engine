#include "TFIDFRanking.h"
#include "../ranking/TFIDF.h"
#include "../document/Document.h"

void TFIDFRanking::visit(std::shared_ptr<SearchEngine> searchEngine) {
    auto& docs = searchEngine->results();
    auto cmp = [&](const Document &a, const Document &b) {
        float sA = TFIDF::instance().calculateTFIDF(a, searchEngine->currentQuery());
        float sB = TFIDF::instance().calculateTFIDF(b, searchEngine->currentQuery());
        return sA > sB;
    };
    std::sort(docs.begin(), docs.end(), cmp);
}
