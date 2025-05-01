# Search Engine Project  
## Member
- *23120215 - Ngô Đa Báu - Leader*  
- *23120219 - Nguyễn Văn Chiến*  

## Coding conventions
- Class name: CamelCase
- Prive field: _camelCase
- Method: cameCase (starts with verb)

## Progress
### Phase 1 tasks (11/04 - 13/04) - Done
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
- Prepare project requirements for progress reporting

## Project Proposal  
### Introduction  
Search Engine Project is an academic search engine application designed to search relevant academic information and records in universities. With this application, **students** in universities can search academic information based on keywords and titles provided for search.  

Most universities have their own websites that provide information regarding students' research papers, project source codes and project reports. These records can be used as a reference by new students entering universities. This search engine provides a platform to find out such records, information and data that can help students in the academic works.  

### Describe  
This project is expected to include the following components:  
- University Management System to organize and manage university-specific data.
- Documentation system of each university (stored as text files) for easy access.
- Search Algorithms, such as keyword-based or semantic search, to retrieve relevant academic information efficiently.
- Records management system to save and manage user search history for future reference.
- An infrastructure to support system operations, ensuring scalability and reliability.
- A Simple User Interface (CLI or web-based) to allow users to interact with the system intuitively.

### Detail  
After this project is finished, the program might operate as follows:  
1. You enter a word or phrase to search for academic information.
2. This search will be saved in the records management system.
3. The search algorithm processes the query and retrieves relevant results.
4. The Command Line Interface (CLI) displays a list of results.
5. You have the following options:
    - View or download one of the results.
    - Continue searching with a new query.
    - Exit the program.

## Software Architecture
This project is designed using the **Layered Architecture** approach, combined with the **SOLID Principles**, to ensure maintainability, scalability, and robustness.

### Layered Architecture
The system is divided into the following layers:

1. **Presentation Layer (CLI or UI):**  
    This layer is responsible for interacting with the user. It displays search results, accepts user input, and communicates with the application layer.

2. **Application Layer:**  
    This layer contains the core logic of the application, such as managing user queries, coordinating search operations, and handling user actions like viewing or downloading results.

3. **Domain Layer:**  
    This layer encapsulates the business logic of the system. It includes components like `SearchEngine`, `SearchAlgorithm`, and `RecordsManager`, which implement the core functionality of the search engine.

4. **Infrastructure Layer:**  
    This layer handles low-level details such as file I/O, database access, and external libraries. It includes components like `LoaderFile` for reading files and `Index` for building and managing search indices.

### SOLID Principles
- **Single Responsibility Principle (SRP):**  
    Each class in the project has a single responsibility  
    `Index`: Build index for references  
    `LoaderFile`: Handle read file  
    `Search`: Search document for query  
    etc...

- **Open/Closed Principle (OCP):**  
    The system is designed to allow extension without modifying existing code.  
    `ISearch`: Interface extension for specific searches like document type, title, author or general document

- **Liskov's Substitution Principle (LSP):**  
    Subclasses can replace their parent classes without affecting the functionality.

- **Interface Segregation Principle (ISP):**  
    Interfaces are designed to be specific to the needs of the clients.

- **Dependency Inversion Principle (DIP):**  
    High-level modules do not depend on low-level modules; both depend on abstractions. For example, `ISearch`, `IIndex`, and `ILoader`.

This combination of **Layered Architecture** and **SOLID Principles** ensures that the project is modular, extensible, and easy to maintain.

### Design Pattern
The following design patterns are used in this project:

- **Factory Pattern:**  
    Used to create instances of search algorithms (`KeywordSearch`, `SemanticSearch`, etc.) based on user preferences or input.

- **Singleton Pattern:**  
    Ensures that certain classes, such as `RecordsManager`, have only one instance throughout the application to maintain consistency in managing user search history.

- **Strategy Pattern:**  
    Allows the `SearchEngine` to switch between different search algorithms (e.g., keyword-based or semantic search) at runtime by encapsulating them as interchangeable strategies.

- **Observer Pattern:**  
    Used to notify components (e.g., CLI or UI) when the search results are updated or when a new search is performed.

- **Decorator Pattern:**  
    Used to add additional functionality to search results, such as filtering or sorting, without modifying the core search algorithm.

- **Command Pattern:**  
    Used to encapsulate user actions (e.g., view, download, or exit) as commands, making it easier to extend or modify the CLI behavior.
