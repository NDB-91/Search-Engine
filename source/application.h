#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>

#include "user.h"
#include "search/SearchEngine.h"


class Application {
public:
    Application();
    ~Application();

    void run();

private:
    User* _currentUser;
    SearchEngine* _searchEngine;
};

#endif