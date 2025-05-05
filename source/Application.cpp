#include "Application.h"
#include "account/FileAccountRepository.h"
#include "Utils.h"

Application::Application() {
    _repo = std::make_shared<FileAccountRepository>(ACCOUNTS);
    _accountService = std::make_shared<AccountService>(_repo);
    _searchEngine = std::make_shared<SearchEngine>();
}

void Application::run() {
    std::cout << "Welcome to the Search Engine Application!\n";
    int choice;
    do {
        displayChoice();
        std::cout << "Enter your choice: ";
        choice = getChoice();
        handleChoice(choice);
    } while (choice != 4);
    std::cout << "Thank you for using the Search Engine Application!\n";
    std::cout << "Goodbye!\n";
    std::cout << "Exiting application...\n";
    std::cout << "Application exited successfully.\n";
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
}

void Application::displayChoice() const {
    std::cout << "1. Login\n";
    std::cout << "2. Register Student\n";
    std::cout << "3. Register Lecturer\n";
    std::cout << "4. Exit\n";
}

int Application::getChoice() const {
    int c;
    std::cin >> c;
    std::cin.ignore();
    return c;
}

void Application::handleChoice(int choice) {
    switch(choice) {
    case 1:
        if(login()){
            search();
        }
        break;
    case 2:
        registerStudent();
        break;
    case 3:
        registerLecturer();
        break;
    case 4:
        std::cout << "Goodbye!\n";
        break;
    default:
        std::cout << "Invalid choice\n";
    }
}

bool Application::login() {
    std::string email, password;
    std::cout << "Email: "; std::cin >> email;
    std::cin.ignore();
    std::cout << "Password: "; std::cin >> password;
    std::cin.ignore();
    bool success = _accountService->login(email, password);
    if (success){
        std::cout << "Login successfully!\n";
    }
    else{
        std::cout << "Login failed.\n";
    }
    return success;
}

void Application::registerStudent() {
    std::string email, name, university;
    std::string password;
    std::cout << "Email: "; std::cin >> email;
    std::cin.ignore();
    std::cout << "Name: "; std::getline(std::cin, name);
    std::cout << "University: "; std::getline(std::cin, university);
    std::cout << "Password: "; std::cin >> password;
    std::cin.ignore();
    Student student(email, name, convertUniversityName(university));
    _accountService->registerStudent(student, password);
    std::cout << "Student registered!\n";
}

void Application::registerLecturer() {
    std::string email, name, department, university;
    std::string password;
    std::cout << "Email: "; std::cin >> email;
    std::cin.ignore();
    std::cout << "Name: "; std::getline(std::cin, name);
    std::cout << "Department: "; std::getline(std::cin, department);
    std::cout << "University: "; std::getline(std::cin, university);
    std::cout << "Password: "; std::cin >> password;
    std::cin.ignore();
    Lecturer lecturer(email, name, convertDepartment(department), convertUniversityName(university));
    _accountService->registerLecturer(lecturer, password);
    std::cout << "Lecturer registered!\n";
}