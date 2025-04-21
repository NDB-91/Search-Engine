#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>

#include "user.h"
#include "search-engine.h"
#include "document.h"

#define DIRECTORY_PATH "references/"

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