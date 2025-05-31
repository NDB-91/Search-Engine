#include "Application.h"
#include "account/FileAccountRepository.h"
#include "Utils.h"
#include "visitor/TFIDFRanking.h"
#include "suggester/SearchSuggester.h"
#include "terminal/PosixTerminal.h"


Application::Application() {
    
}

void Application::config() {
    _accountService = std::make_shared<AccountService>(std::make_shared<FileAccountRepository>(ACCOUNTS));
    _searchEngine = std::make_shared<SearchEngine>();
    _rankingVisitor = std::make_shared<TFIDFRanking>();
    _suggester = std::make_shared<SearchSuggester>();

}

void Application::run() {
    std::cout << "<===== Welcome to the Search Engine Application for finding documents! =====>\n";
    int choice;
    do {
        displayChoice();
        choice = getChoice();
        handleChoice(choice);
    } while (choice != 4);
    std::cout << "\n<===== Thank you for using the Search Engine Application! =====>\n";
}

void Application::search() {
    _terminal = std::make_shared<PosixTerminal>();
    _terminal->write("> Enter search query (or 'exit' to quit): ");
    std::string buffer;
    while (true) {
        char c = _terminal->readChar();
        if(c == '\n') {
            _terminal->write("\n");
            if(buffer == "exit") {
                break;
            }
            _searchEngine->search(buffer);
            SearchLogger::instance().log(TextProcessor::toLower(buffer));
            _searchEngine->displayResults(_rankingVisitor);
            buffer.clear();
            _terminal->write("> Enter search query (or 'exit' to quit): ");
            continue;
        }
        if (c == 127 || c == '\b') {
            if (!buffer.empty()) {
                buffer.pop_back();
                _terminal->write("\b \b");
                _terminal->write("\033[K");

                auto sug = _suggester->suggest(buffer);
                if (!sug.empty()) {
                    const auto &full = sug[0];
                    if (full.size() > buffer.size()) {
                        auto hint = full.substr(buffer.size());
                        _terminal->write("\033[K");
                        _terminal->write("\033[90m" + hint + "\033[0m");
                        _terminal->write("\033[" + std::to_string(hint.size()) + "D");
                    } else {
                        _terminal->write("\033[K");
                    }
                }
            }
            continue;
        }
        if (c == '\t') {
            auto sug = _suggester->suggest(buffer);
            if (!sug.empty()) {
                const auto &full = sug[0];
                if (full.size() > buffer.size()) {
                    auto completion = full.substr(buffer.size());
                    // Print in gray, then reset color
                    _terminal->write("\033[90m" + completion + "\033[0m");
                    // Move cursor to end of completion
                    buffer += completion;
                }
            }
            continue;
        }

        buffer.push_back(c);
        _terminal->write(std::string(1, c));
        _terminal->write("\033[K");

        auto sug = _suggester->suggest(buffer);
        if (!sug.empty()) {
            const auto &full = sug[0];
            if (full.size() > buffer.size()) {
                auto hint = full.substr(buffer.size());
                _terminal->write("\033[K");
                _terminal->write("\033[90m" + hint + "\033[0m");
                _terminal->write("\033[" + std::to_string(hint.size()) + "D");
            } else {
                _terminal->write("\033[K");
            }
        }
    }
    _terminal.reset();
}

void Application::displayChoice() const {
    std::cout << "The list of options available to you.\n";
    std::cout << "\t1. Login\n";
    std::cout << "\t2. Register Student\n";
    std::cout << "\t3. Register Lecturer\n";
    std::cout << "\t4. Exit\n";
}

int Application::getChoice() const {
    int choice;
    while (true) {
        std::cout << "Please enter your choice (1-4): ";
        std::string input;
        std::getline(std::cin, input);
        if (input.empty() || input.find_first_not_of("0123456789") != std::string::npos) {
            std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }
        try {
            choice = std::stoi(input);

            if (choice < 1 || choice > 4) {
                throw std::invalid_argument("Choice must be between 1 and 4.");
            }
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid input: " << e.what() << "\n";
        }
    }
    return choice;
}


void Application::handleChoice(int choice) {
    switch(choice) {
    case 1:
        if(login()){
            std::cout << "\n<--- Let's search a document! --->\n";
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
    std::cout << "Email     : "; 
    std::getline(std::cin, email);
    std::cout << "Password  : ";
    std::getline(std::cin, password);
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
    while (true) {
        try {
            std::cout << "Email     : "; 
            std::getline(std::cin, email);
            validateEmail(email, "student");
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << "\nPlease try again.\n";
        }
    }

    std::cout << "Name      : "; 
    std::getline(std::cin, name);

    while (true) {
        try {
            std::cout << "University: "; 
            std::getline(std::cin, university);
            validateUniversity(university);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << "\nPlease try again.\n";
        }
    }

    while (true) {
        std::cout << "Password  : ";
        std::getline(std::cin, password);
        try {
            validatePassword(password);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << "\nPlease try again.\n";
        }
    }
    Student student(email, name, convertUniversityName(university));
    _accountService->registerStudent(student, password);
    std::cout << "Student registered!\n";
}

void Application::registerLecturer() {
    std::string email, name, department, university;
    std::string password;

    while (true) {
        try {
            std::cout << "Email     : ";
            std::getline(std::cin, email);
            validateEmail(email, "lecturer");
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << "\nPlease try again.\n";
        }
    }

    std::cout << "Name      : ";
    std::getline(std::cin, name);

    while (true) {
        try {
            std::cout << "Department: ";
            std::getline(std::cin, department);
            validateDepartment(department);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << "\nPlease try again.\n";
        }
    }

    while (true) {
        try {
            std::cout << "University: ";
            std::getline(std::cin, university);
            validateUniversity(university);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << "\nPlease try again.\n";
        }
    }

    while (true) {
        std::cout << "Password  : ";
        std::getline(std::cin, password);
        try {
            validatePassword(password);
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << "\nPlease try again.\n";
        }
    }

    Lecturer lecturer(email, name, convertDepartment(department), convertUniversityName(university));
    _accountService->registerLecturer(lecturer, password);
    std::cout << "Lecturer registered!\n";
}
