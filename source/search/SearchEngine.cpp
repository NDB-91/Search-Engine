#include <iostream>

#include "SearchEngine.h"
#include "SearchKeyword.h"
#include "../document/DocumentManager.h"
#include "../text/TextProcessor.h"
#include "../visitor/IRankingVisitor.h"

SearchEngine::SearchEngine() {
    _search = std::make_shared<SearchKeyword>();
}

void SearchEngine::search(const std::string& query) {
    _currentQuery = query;
    std::vector<std::string> ids = _search->search(TextProcessor::toLower(query));
    _results.clear();
    for (const auto& id : ids) {
        Document doc = DocumentManager::instance().getDocument(id);
        if (!doc.id().empty()) {
            _results.emplace_back(doc);
        }
    }
}

std::vector<Document>& SearchEngine::results() {
    return _results;
}

std::string SearchEngine::currentQuery() const {
    return _currentQuery;
}

void SearchEngine::displayResults(std::shared_ptr<IRankingVisitor> visitor) {
    accept(visitor);
    std::cout << "--- The results for the query '" << _currentQuery << "' ---\n";
    for(int i = 0; i < _results.size(); ++i) {
        std::string title = _results[i].title();
        std::cout << i + 1 << ". " << title << "\n";
    }
    std::cout << "\n";
}

void SearchEngine::clearResults() {
    _results.clear();
}

void SearchEngine::accept(std::shared_ptr<IVisitor> visitor) {
    auto rankingVisitor = std::dynamic_pointer_cast<IRankingVisitor>(visitor);
    if (rankingVisitor) {
        std::shared_ptr<SearchEngine> self = shared_from_this();
        rankingVisitor->visit(self);
    }
    else {
        std::cerr << "Invalid visitor type.\n";
    }
}