# Library_Management_System

A console-based Library Management System built in C. This project was developed as part of my first-semester coursework to demonstrate understanding of procedural programming, file handling, and data structures in C.

##  Features

* **Add New Books:** Input book details (ID, Title, Author, etc.) and store them in the database.
* **View All Books:** Display a list of all books currently in the library.
* **Search Books:** Find books by ID or Title.
* **Issue & Return:** Track borrowed books (checks availability and updates status).
* **Delete Records:** Remove old or lost books from the system.
* **File Handling:** All data is persisted in text/binary files so records are saved even after the program closes.

##  Tech Stack

* **Language:** C
* **Concepts Used:** Structures, Pointers, File I/O, Strings, Switch-Case menus.

##  How to Run

1.  **Clone the repository** (or download the ZIP):
    ```bash
    git clone [https://github.com/your-username/library-management-system.git](https://github.com/your-username/library-management-system.git)
    ```
2.  **Navigate to the project directory:**
    ```bash
    cd library-management-system
    ```
3.  **Compile the code:**
    If you are using GCC:
    ```bash
    gcc main.c -o library_app
    ```
4.  **Run the application:**
    * On Windows:
        ```bash
        library_app.exe
        ```
    * On Linux/Mac:
        ```bash
        ./library_app
        ```

##  Contributing

This is a student project, but suggestions are welcome! Feel free to open an issue or pull request if you find bugs or want to improve the code.

##  License

This project is open-source and available under the [MIT License](LICENSE).
