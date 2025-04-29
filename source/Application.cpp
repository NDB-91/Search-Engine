#include "Application.h"
#include "auth/AuthWithFile.h"
#include "Utils.h"

Application::Application() {
    _currentUser = std::make_shared<User>();
    _searchEngine = std::make_shared<SearchEngine>();
}

void Application::run() {
    int roleChoice;
    do {
        std::cout << "Welcome to the Application!\n";
        std::cout << "Please choose your role:\n";
        std::cout << "1. Student\n";
        std::cout << "2. Lecturer\n";
        std::cout << "3. Exit\n";
        std::cout << "Please select your role (1-3): ";
        std::cin >> roleChoice;

        switch (roleChoice) {
            case 1:
                handleStudent();
                break;
            case 2:
                handleLecturer();
                break;
            case 3:
                std::cout << "Exiting the application...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (roleChoice != 3);
}

void Application::handleStudent() {
    int choice;

    do {
        AuthWithFile auth("account/student.txt", "account/lecturer.txt");
        std::cout << auth.getFile();

        std::cout << "\nStudent - Please choose an action:\n";
        std::cout << "1. Login\n";
        std::cout << "2. Sign Up\n";
        std::cout << "3. Back\n";
        std::cout << "Please select an option (1-3): ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) { 
            std::string email, password;
            std::cout << "Enter email: ";
            std::getline(std::cin, email);
            std::cout << "Enter password: ";
            std::getline(std::cin, password);

            if (auth.loginStudent(email, password)) {
                std::cout << "Login successful!\n";
                search();
                break;
            } else {
                std::cout << "Login failed. Please try again.\n";
            }
        }
        else if (choice == 2) { // Sign Up
            std::string email, name, university, password;
            std::cout << "Enter email: ";
            std::getline(std::cin, email);
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            std::cout << "Enter university name: ";
            std::getline(std::cin, university);
            std::cout << "Enter password: ";
            std::getline(std::cin, password);

            bool success = auth.registerStudent(email, name, convertUniversityName(university), password);
            if (success) {
                std::cout << "Sign Up successful! You can now login.\n";
            } else {
                std::cout << "Sign Up failed! Please try again.\n";
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            std::cout << "Invalid choice. Please enter 1-3.\n";
        }
    } while (true);
}

void Application::handleLecturer() {
    AuthWithFile auth("account/student.txt", "account/lecturer.txt");
    std::cout << auth.getFile();
    int choice;
    do {
        std::cout << "\nLecturer - Please choose an action:\n";
        std::cout << "1. Login\n";
        std::cout << "2. Sign Up\n";
        std::cout << "3. Back\n";
        std::cout << "Please select an option (1-3): ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string email, password;
            std::cout << "Enter email: ";
            std::getline(std::cin, email);
            std::cout << "Enter password: ";
            std::getline(std::cin, password);

            if (auth.loginLecturer(email, password)) {
                std::cout << "Login successful!\n";
                search();
                break;
            } else {
                std::cout << "Login failed. Please try again.\n";
            }
        }
        else if (choice == 2) { // Sign Up
            std::string email, name, department, university, password;
            std::cout << "Enter email: ";
            std::getline(std::cin, email);
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            std::cout << "Enter department: ";
            std::getline(std::cin, department);
            std::cout << "Enter university name: ";
            std::getline(std::cin, university);
            std::cout << "Enter password: ";
            std::getline(std::cin, password);

            bool success = auth.registerLecturer(email, name, convertDepartment(department), convertUniversityName(university), password);
            if (success) {
                std::cout << "Sign Up successful! You can now login.\n";
            } else {
                std::cout << "Sign Up failed! Please try again.\n";
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            std::cout << "Invalid choice. Please enter 1-3.\n";
        }
    } while (true);
}

void Application::search() {
    std::string query;
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
    _currentUser->logout();
    std::cout << "Thank you for using the Search Engine Application!\n";
    std::cout << "Goodbye!\n";
    std::cout << "Exiting application...\n";
    std::cout << "Application exited successfully.\n";
}