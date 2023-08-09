#include <iostream>
#include <vector>
#include "Hash_Table.h"
#include "AVLTree.h"
#include "parser.h"
#include "student.h"
#include "book.h"
#include "borrowed_book.h"
#include "utilities.h"

using namespace std;

int main()
{
    // load data from CSV files
    vector<Student> students = readStudentCSV("students.csv");
    vector<Book> books = readBookCSV("books.csv");
    // vector<BorrowedBook> borrowedBooks = readBorrowedCSV("borrowed_books.csv");

    // initialize hash tables
    HashTable<Student> studentTable(static_cast<int>(students.size())); // explicitly casting the value from size_t to int
    HashTable<Book> bookTable(static_cast<int>(books.size()));

    // populate hash tables
    populateStudentHashTable(studentTable, students);
    populateBookHashTable(bookTable, books);

    // print the hash table for testing
    cout << "STUDENT DATA:" << endl;
    studentTable.printTable();
    cout << "BOOK DATA:" << endl;
    bookTable.printTable();

    // string title;
    // cout << "\nENTER A BOOK TITLE: ";
    // cin >> title;

    // // Retrieve the specific book from the bookTable
    // AVLTree<Book> *bookAVLTree = bookTable.search(title);

    // if (bookAVLTree)
    // {
    //     // Call the isBookAvailable function on the retrieved book object
    //     Book bookInstance = bookAVLTree->getRootValue(); // Assuming you have a method to get the root value
    //     bool available = bookInstance.isBookAvailable(bookTable, title);

    //     if (available)
    //     {
    //         cout << "The book is available." << endl;
    //     }
    //     else
    //     {
    //         cout << "The book is not available." << endl;
    //     }
    // }
    // else
    // {
    //     cout << "Book not found." << endl;
    // }

    return 0;
}
