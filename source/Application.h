#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <memory>
#include <iostream>

#include "text/TextProcessor.h"
#include "service/AccountService.h"
#include "search/SearchEngine.h"
#include "visitor/IRankingVisitor.h"
#include "logger/SearchLogger.h"
#include "suggester/ISuggester.h"
#include "terminal/ITerminal.h"

#define ACCOUNTS "database/account/accounts.txt"

/**
 * @class Application
 * @brief The main application class that handles user interaction, authentication, and search functionality.
 */
class Application {
public:
    /**
     * @brief Constructs the Application object and initializes services.
     */
    Application();

    /**
     * @brief Configures the application settings and services.
     */
    void config();

    /**
     * @brief Starts the main application loop.
     */
    void run();

    /**
     * @brief Handles the search functionality of the application.
     */
    void search();
private:
    std::shared_ptr<AccountService> _accountService; ///< Service for managing accounts.
    std::shared_ptr<SearchEngine> _searchEngine; ///< Search engine for handling search queries.
    std::shared_ptr<IRankingVisitor> _rankingVisitor; ///< Visitor for ranking search results.
    std::shared_ptr<ISuggester> _suggester; ///< Suggester for providing search suggestions.
    std::shared_ptr<ITerminal> _terminal; ///< Terminal interface for user input/output.

    /**
     * @brief Displays the menu choices to the user.
     */
    void displayChoice() const;

    /**
     * @brief Gets the user's menu choice.
     * @return The user's choice as an integer.
     */
    int getChoice() const;

    /**
     * @brief Handles the user's menu choice.
     * @param choice The user's selected menu option.
     */
    void handleChoice(int choice);

    /**
     * @brief Handles the login functionality for users.
     * @return True if login is successful, false otherwise.
     */
    bool login();

    /**
     * @brief Registers a new student account.
     */
    void registerStudent();

    /**
     * @brief Registers a new lecturer account.
     */
    void registerLecturer();
};

#endif