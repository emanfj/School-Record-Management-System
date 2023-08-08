#include <iostream>
#include <vector>

#include "Hash_Table.h"
#include "AVLTree.h"
#include "parser.h"
#include "student.h"
#include "book.h"
#include "borrowed_book.h"

using namespace std;

//functions for populating hash tables
void populateHashTable(HashTable<Student>& studentTable, const vector<Student>& students) {
    for (const Student& student : students) {
        studentTable.insert(student.getId(), student);
    }
}

void populateHashTable(HashTable<Book>& bookTable, const vector<Book>& books) {
    for (const Book& book : books) {
        bookTable.insert(book.getId(), book);
    }
}
int main() 
{
    //load data from CSV files
    vector<Student> students = readStudentCSV("students.csv");
    vector<Book> books = readBookCSV("books.csv");
   // vector<BorrowedBook> borrowedBooks = readBorrowedCSV("borrowed_books.csv");

    //initialize hash tables
    HashTable<Student> studentTable(static_cast<int>(students.size())); //explicitly casting the value from size_t to int
    HashTable<Book> bookTable(static_cast<int>(books.size()));


    //populate hash tables
    populateHashTable(studentTable, students);
    populateHashTable(bookTable, books);

    //print the hash table for testing
    cout << "STUDENT DATA:" << endl;
    studentTable.printTable();
    cout << "BOOK DATA:" << endl;
    bookTable.printTable();
   
    return 0;
}
