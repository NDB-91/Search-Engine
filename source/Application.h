#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <memory>
#include <iostream>

#include "service/AccountService.h"
#include "search/SearchEngine.h"

#define ACCOUNTS "database/account/accounts.txt"

class Application {
public:
    Application();

    void run();
    void search();
private:
    std::shared_ptr<IAccountRepository> _repo;
    std::shared_ptr<AccountService> _accountService;
    std::shared_ptr<SearchEngine> _searchEngine;

    void displayChoice() const;
    int getChoice() const;
    void handleChoice(int choice);
    bool login();
    void registerStudent();
    void registerLecturer();
};

#endif