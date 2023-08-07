#include <iostream>
#include <vector>

#include "HashTable.h"
#include "AVLTree.h"

#include "Student.h"
#include "Book.h"
#include "BorrowedBook.h"

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
    vector<BorrowedBook> borrowedBooks = readBorrowedCSV("borrowed_books.csv");

    //initialize hash tables
    HashTable<Student> studentTable(students.size());
    HashTable<Book> bookTable(books.size());

    //populate hash tables
    populateHashTable(studentTable, students);
    populateHashTable(bookTable, books);

    return 0;
}
