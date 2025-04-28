#include "Application.h"

Application::Application() {
    _currentUser = std::make_shared<User>();
    _searchEngine = std::make_shared<SearchEngine>();
}

void Application::run() {
    std::cout << "Welcome to the Search Engine Application!\n";
    std::cout << "Please login to continue.\n";
    std::string username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    _currentUser->login(username, password);
    if (_currentUser->IsLoggedIn()) {
        std::cout << "Login successful!\n";
        std::string query;
        std::cin.ignore();
        while (true) {
            std::cout << "Enter search query (or 'exit' to quit): ";
            std::getline(std::cin, query);
            if (query == "exit") {
                break;
            }
            _searchEngine->search(query);
            _searchEngine->displayResults();
            _searchEngine->clearResults();
        }
    } else {
        std::cout << "Login failed. Please try again.\n";
    }
    _currentUser->logout();
    std::cout << "Thank you for using the Search Engine Application!\n";
    std::cout << "Goodbye!\n";
    std::cout << "Exiting application...\n";
    std::cout << "Application exited successfully.\n";
}