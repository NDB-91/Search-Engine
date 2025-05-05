# Search Engine Project  
## Introduction
### Member
- *23120215 - Ngô Đa Báu - Leader*  
- *23120219 - Nguyễn Văn Chiến*  

### Work done
- Ngô Đa Báu  
    - A Search Engine based on inverted index  
    - Generate sample data  
    - Code synthesis  
    - Create unit test (test plan, test cases and test report)  
- Nguyễn Văn Chiến
    - An Account Mangement System that related to universities (Students, Lecturers)
    - Generate documentation to describe the architecture (using Doxygen)  

**The proportion of members' contributions to the project**
- Ngô Đa Báu - 50%  
- Nguyễn Văn Chiến - 40%  

**Member score ratio:** divide equally

## Conventions
### Naming
- Class name: CamelCase
- Prive field: _camelCase
- Method: cameCase (starts with verb)
- File name: CamelCase.* (h/cpp) (main file and test file not included)
- Folder name: kabal-case
- Test file name: test_name.cpp (main_test.cpp not included)

### Coding
- Separate declaration and implementation
- System libraries above, defined libraries below
- private under public (protected middle if any)
- Use smart pointer for pointer
- Do not use friend class
- Do not use string literals for open files (use #define instead)

## Compile and run the program
1. Run and Debug button of VSCode with configured .vscode filed  
2. Bash  
```Bash
$ cd source
$ g++ -std=c++2b *.cpp **/*.cpp -o ../release/program
$ ../release/program
```

## Project Proposal  
### Introduction  
Search Engine Project is an search engine application designed to search relevant information and records in universities. With this application, **students** in universities can search information based on keywords and titles provided for search.  

Most universities have their own websites that provide information regarding students' research papers, project source codes and project reports. These records can be used as a reference by new students entering universities. This search engine provides a platform to find out such records, information and data that can help students during their studies.

### Describe  
This project is expected to include the following components:  
- University Management System to organize and manage university-specific data.
- Documentation system of each university (stored as text files) for easy access.
- Search Algorithms, such as keyword-based or semantic search, to retrieve relevant information efficiently.
- Records management system to save and manage user search history for future reference.
- An infrastructure to support system operations, ensuring scalability and reliability.
- A Simple User Interface (CLI or web-based) to allow users to interact with the system intuitively.

### Detail  
After this project is finished, the program might operate as follows:  
1. You log in or register an account to access the application.
2. You enter a word or phrase to search for academic information.
3. This search will be saved in the records management system.
4. The search algorithm processes the query and retrieves relevant results.
5. The Command Line Interface (CLI) displays a list of results.
6. You have the following options:
    - View or download one of the results.
    - Continue searching with a new query.
    - Exit the program.


### Software Architecture
This project is designed using the **Layered Architecture** approach, combined with the **SOLID Principles**, to ensure maintainability, scalability, and robustness.

#### Layered Architecture
The system is divided into the following layers:

1. **Presentation Layer (CLI or UI):**  
    This layer is responsible for interacting with the user. It displays search results, accepts user input, and communicates with the application layer.

2. **Application Layer:**  
    This layer contains the core logic of the application, such as managing user queries, coordinating search operations, and handling user actions like viewing or downloading results.

3. **Domain Layer:**  
    This layer encapsulates the business logic of the system. It includes components like `SearchEngine`, `IndexSearcher`, and `AccountFactory`, which implement the core functionality of the search engine.

4. **Infrastructure Layer:**  
    This layer handles low-level details such as file I/O, database access, and external libraries. It includes components like `LoaderFile` for reading files and `IndexManager` for building and managing search indices.

#### SOLID Principles
- **Single Responsibility Principle (SRP):**  
    Each class in the project has a single responsibility.  
    `Document`: Store a document  
    `Student`: Store a student  
    `IIndexBuilder`: Handle building indexes  
    `LoaderFile`: Handle read file (retrieve document contents)  
    `IndexSearcher`: Intermediate between search and indexing  
    etc...  

- **Open/Closed Principle (OCP):**  
    The system is designed to allow extension without modifying existing code.  
    `IAccount`: Interface for adding a new account type  
    `IIndex`: Interface for adding a new indexer type  
    `SearchBase`: Abstract class that extension for specific searches such as based on keywords, document type, title, author or general document  
    etc...


- **Liskov's Substitution Principle (LSP):**  
    Subclasses can replace their parent classes without affecting the functionality. For example, `StudentAccount`, `Lecturer Account`, `InvertedIndexBuilder`, etc...   

- **Interface Segregation Principle (ISP):**  
    Interfaces are designed to be specific to the needs of the clients.

- **Dependency Inversion Principle (DIP):**  
    High-level modules do not depend on low-level modules; both depend on abstractions. For example, `IAccount`, `IIndex`, and `ISearch`, etc...  

This combination of **Layered Architecture** and **SOLID Principles** ensures that the project is modular, extensible, and easy to maintain.

### Design Pattern
The following design patterns are used in this project:

- **Factory Pattern:**  
    `AccountFactory`: Create account types like `StudentAccount`, `LecturerAccount`  

- **Singleton Pattern:**  
    `DocumentManager`: Handle adding and retrieving documents  
    `IndexManager`: Handling the construction of an index type  
    `LectureManager`: Handle adding and retrieving information related to the Lecturer object  
    `StudentManager`: Handle adding and retrieving information related to the Student object  


- **Builder Pattern:**  
    `IIndexBuilder`: Interface that defines the construction steps required to create an Index.  
    `InvertedIndexBuilder`: The class implementing the IInderBuilder interface is responsible for building a concrete Index type called InvertedIndex  

- **Adapter Pattern:**  
    `InderSearcher`: A bridge between IIndex and BaseBase  

### Reference
https://github.com/alexandria-org/alexandria

### Video demo
https://youtu.be/XDi8AcXPEuU

## Progress
### Phase 1 tasks (11/04 - 13/04)
- Ngô Đa Báu
    - Learn and implement a basic search engine
    - Generate or gather academic documents for universities (stored as text files).
- Nguyễn Văn Chiến (https://drive.google.com/drive/folders/1r5ub6TMLJNeTc8KTuxTEhqJeb2-vHstA)
    - Design a basic document management model for the university
    - Draw a schema for the above model (using ER model or relational model)
    - Describe constraints (if any)
    - Draw a class diagram for the above model.

### Phase 2 tasks (14/04 - 20/04)
- Ngô Đa Báu
    - Continue building search engine
    - Apply SOLID principles, dependency injection principles
    - Demonstrate compliance with OOP principles and principles, use design patterns
- Nguyễn Văn Chiến
    - Implement the designed model - basic document management for university
    - Apply SOLID principles, dependency injection principles
    - Demonstrate compliance with OOP principles and principles, use design patterns

### Phase 3 tasks (22/04 - 29/04)
- Ngô Đa Báu
    - Add Trie Tree for search engine
    - Implement TF-IDF ranking
- Nguyễn Văn Chiến
    - Continue building the document managemen system for the university
    - Apply SOLID principles and dependency injection principles
    - Demonstrate compliance with OOP principles and use design patterns
    - Implement user roles for signing into the application
        - Student: Search documents
        - Lecturer: Search documents and documents

### Phase 4 tasks (1/5 - 5/5)
Prepare project requirements for progress reporting  
- Ngô Đa Báu  
    - Create unit test (test plan, test cases and test report)  
- Nguyễn Văn Chiến  
    - Generate documentation to describe the architecture (using Doxygen)  