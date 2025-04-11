#include "application.h"

Application::Application() {
    currentUser = new User();
    searchEngine = new SearchEngine();
}

Application::~Application() {
    delete currentUser;
    delete searchEngine;
}

void Application::run() {
    std::cout << "Welcome to the Search Engine Application!\n";
    std::cout << "Please login to continue.\n";
    std::string username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    currentUser->login(username, password);
    if (currentUser->IsLoggedIn()) {
        std::cout << "Login successful!\n";
        std::string query;
        std::cin.ignore();
        while (true) {
            std::cout << "Enter search query (or 'exit' to quit): ";
            std::getline(std::cin, query);
            if (query == "exit") {
                break;
            }
            searchEngine->search(query);
            searchEngine->displayResults();
            searchEngine->clearResults();
        }
    } else {
        std::cout << "Login failed. Please try again.\n";
    }
    currentUser->logout();
    std::cout << "Thank you for using the Search Engine Application!\n";
    std::cout << "Goodbye!\n";
    std::cout << "Exiting application...\n";
    std::cout << "Application exited successfully.\n";
}