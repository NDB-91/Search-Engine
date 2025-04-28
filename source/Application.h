#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <memory>
#include <iostream>

#include "User.h"
#include "search/SearchEngine.h"


class Application {
public:
    Application();

    void run();
private:
    std::shared_ptr<User> _currentUser;
    std::shared_ptr<SearchEngine> _searchEngine;
};

#endif