#include <iostream>
#include <vector>

#include "parser.h"
#include "student.h"
#include "book.h"
#include "borrowed_book.h"
#include "utilities.h"
#include "Hash_Table.h"
#include "AVLTree.h"


using namespace std;

int main()
{
    // load data from CSV files
    vector<Student> students = readStudentCSV("students.csv");
    vector<Book> books = readBookCSV("books.csv");

    // initialize hash tables
    HashTable<Student> studentTable(static_cast<int>(students.size()));
    HashTable<Book> bookTable(static_cast<int>(books.size()));
    //creating an empty hash table for borrowed books the same size as book inventory
    HashTable<BorrowedBook> borrowedBookTable(static_cast<int>(books.size()));  

    // populate hash tables
    populateStudentHashTable(studentTable, students);
    populateBookHashTable(bookTable, books);

    int choice;
    do
    {
        cout << "\nMAIN MENU:" << endl;
        cout << "1. Student Management System" << endl;
        cout << "2. Library Management System" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        //to handle invalid user input
        if (!cin) //if the stream is in an error state (e.g., because the user didn't input a number)
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); //clear the error state
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard invalid input
            continue; //jump to the next iteration of the loop
        }


        switch (choice)
        {
        case 1:
        {
            int studentChoice;
            do
            {
                cout << "\n\nSTUDENT MANAGEMENT SYSTEM:" << endl;
                cout << "1. Print Student Data" << endl;
                //more student-related menu items as needed...
                cout << "0. Go Back to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> studentChoice;
                //to handle invalid user input
                if (!cin)
                {
                    cout << "Invalid input. Please enter a number." << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

                switch (studentChoice)
                {
                case 1:
                {
                    cout << "STUDENT DATA:" << endl;
                    studentTable.printTable();
                }
                break;
                    //more cases
                case 0:
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                }
            } while (studentChoice != 0);
        }
        break;
        case 2:
        {
            int libraryChoice;
            do
            {
                cout << "\n\nLIBRARY MANAGEMENT SYSTEM:" << endl;
                cout << "1. Print Book Data" << endl;
                cout << "2. Check if a Book is Available" << endl;
                cout << "3. Print Available Books" << endl;
                cout << "4. Borrow a book" << endl;
                cout << "5. Return a borrowed book" << endl;
                //more book related functions
                cout << "0. Go Back to Main Menu" << endl;
                cout << "Enter your choice: ";
                cin >> libraryChoice;
                //to handle invalid user input
                if (!cin)
                {
                    cout << "Invalid input. Please enter a number." << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

                switch (libraryChoice)
                {
                case 1:
                {
                    cout << "BOOK DATA:" << endl;
                    bookTable.printTable();
                }
                break;
                case 2:
                {
                    string title;
                    cout << "Enter book title to check availability: ";
                    cin.ignore(); // Clear the newline left in the input buffer
                    getline(cin, title);
                    if (Book::isBookAvailable(bookTable, title))
                        cout << "The book is available!" << endl;
                    else
                        cout << "The book is not available." << endl;
                }
                break;
                case 3:
                {
                    Book::retrieveAndPrintAvailableBooks(bookTable);
                }
                break;
                case 4:
                {
                    BorrowedBook::borrowBook(bookTable, borrowedBookTable); 
                }
                break;
                case 5:
                {
                    BorrowedBook::returnBook(bookTable, borrowedBookTable); 
                }
                break;


                case 0:
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                }
            } while (libraryChoice != 0);
        }
        break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    //before exiting program write all hash tables into respective csv files with updated data
    //check if said hash table has had any changes (if possible)
    return 0;
}
