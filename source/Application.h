#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <iostream>

#include "User.h"
#include "search/SearchEngine.h"


class Application {
public:
    Application();
    ~Application();

    void run();
    void handleStudent();
    void handleLecturer();

private:
    User* _currentUser;
    SearchEngine* _searchEngine;
};

#endif