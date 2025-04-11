#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>

#include "user.h"
#include "search-engine.h"

class Application {
public:
    Application();
    ~Application();

    void run();

private:
    User* currentUser;
    SearchEngine* searchEngine;
};

#endif