# School Record Management System

## Introduction
This project provides a system for managing university records, focusing on student and book data. The data is stored in hash tables, with collisions handled by AVL Trees, ensuring balanced searching, insertion, and deletion operations.

## Features
### Student Data Management 🎓: 
  Store and manage student records, including ID, name, age, and grade.
### Book Data Management 📚: 
  Maintain a catalog of books in the library, including ID, title, and publication year.
### Borrowed Book Tracking 📘: 
  Keep track of books borrowed, including borrower's name, issue date, and due date.
### Advanced Search Options 🔍:
  Retrieve student or book records based on various criteria.
  Retrieve all books published in a certain year.
  Promote students to the next grade and handle graduation scenarios.
## Setup and Usage
### Prerequisites
- C++ Compiler (Recommended: GCC, Clang)
- [Optional] CMake for easier building.
### Compilation and Execution

```
# Navigate to the root directory of the project
cd path_to_project

# Compile
g++ -o main main.cpp 

# Run
./main
```
## User Guide
### Main Menu: 
  Navigate through the options using numbered inputs.
### Adding Records:  
  Select the appropriate option from the main menu to add student or book records.
### Searching Records: 
  Use the search functionality to retrieve data based on different criteria.
### Modifying Records: 
  Choose the appropriate menu option to update, promote, or delete records.

## Implementation Details
### Hash Table: 
  Uses a custom-built hash table with collision handling via AVL Trees, ensuring a balanced tree structure for efficient operations.
### File Management: 
  Reads initial data from CSV files and updates them when changes occur.
