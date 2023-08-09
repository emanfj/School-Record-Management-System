// TEMPLATE FOR BOOK DATA
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

#include "AVLTree.h"
#include "Hash_Table.h"
// #include "utilities.h"

class Book
{
    int id;
    std::string title;
    std::string author;
    int publishing_year;
    bool isAvailable;
    int quantity;

public:
    // constructor for book instance
    Book(int id, const std::string &title, const std::string &author, int year, bool isAvailable, int quantity)
        : id(id), title(title), author(author), publishing_year(year), isAvailable(isAvailable), quantity(quantity) {}

    // getter functions
    int getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getYear() const { return publishing_year; }
    bool getAvailability() const { return isAvailable; }
    int getQuantity() const { return quantity; }

    // setter (helper) functions
    void setQuantity(int newQuantity) { this->quantity = newQuantity; }
    void setAvailability(bool availability) { this->isAvailable = availability; }
    void setId(int newId) { this->id = newId; }
    void setTitle(std::string newTitle) { this->title = newTitle; }
    void setYear(int newYear) { this->publishing_year = newYear; }
    void setAuthor(std::string newAuthor) { this->author = newAuthor; }

    // for printing book details
    void print() const
    {
        std::cout << "Book ID: " << id << "\nTitle: " << title << "\nPublishing Year: " << publishing_year << "\nBook availability status: " << isAvailable << "\nAuthor: "
                  << author << "\nQuantity: " << quantity << std::endl;
    }
    /*void print() const
    {
        //print the current instance of the class using the overloaded output stream operator
        std::cout << *this;
    }*/

    // function to switch between availability status of a book
    void updateAvailabilityStatus()
    {
        if (getQuantity() > 0)
        {
            setAvailability(true);
        }
        else
        {
            setAvailability(false);
        }
    }

    // checks if a book is available or not
    bool isBookAvailable(HashTable<Book> &bookTable, const string &title)
    {
        // get the AVL tree corresponding to the title
        AVLTree<Book> *tree = bookTable.search(title);
        if (tree)
        {
            return getAvailability();
        }

        // if (tree)
        // {
        //     //search for the book in the tree
        //     Book* book = tree->search(title);

        //     if (book)
        //     {
        //         //if the book is available check if it's available
        //         return getAvailability();
        //     }
        // }

        // if the tree is not found or the book is not found in the tree
        return false; // book not found or not available
    }

    // retrieve books that are set as available
    void retrieveAndPrintAvailableBooks(HashTable<Book> &bookTable)
    {
        cout << "Available Books:" << endl;

        // get all items from the hash table
        std::vector<HashTable<Book>::Item *> items = bookTable.getItems();

        // iterate through the hash table to find the available books
        for (int i = 0; i < items.size(); i++)
        {
            AVLTree<Book> *avlTree = items[i]->value; // Access the 'value' field of the Item

            if (avlTree != nullptr)
            {
                // get all books from the AVL tree
                std::vector<Book> books = avlTree->getValues();

                // loop over the books and print the ones that are available
                for (int j = 0; j < books.size(); j++)
                    if (books[j].getAvailability())
                        cout << books[j] << endl;
            }
        }
    }
};

// operator overloading for comparison operators
bool operator<(const Book &lhs, const Book &rhs)
{
    return lhs.getId() < rhs.getId();
}

bool operator>(const Book &lhs, const Book &rhs)
{
    return lhs.getId() > rhs.getId();
}

bool operator<=(const Book &lhs, const Book &rhs)
{
    return lhs.getId() <= rhs.getId();
}

bool operator>=(const Book &lhs, const Book &rhs)
{
    return lhs.getId() >= rhs.getId();
}

bool operator==(const Book &lhs, const Book &rhs)
{
    return lhs.getId() == rhs.getId();
}

bool operator!=(const Book &lhs, const Book &rhs)
{
    return lhs.getId() != rhs.getId();
}

// operator overloading for output stream operator
std::ostream &operator<<(std::ostream &os, const Book &book)
{
    os << "\nBook ID: " << book.getId() << "\nTitle: " << book.getTitle() << "\nPublishing Year: " << book.getYear()
       << "\nBook availability status: " << std::boolalpha << book.getAvailability() << "\nAuthor: " << book.getAuthor()
       << "\nQuantity: " << book.getQuantity() << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Book &book)
{
    int id;
    std::string title;
    std::string author;
    int year;
    bool availability;
    int quantity;

    // Read data from input stream
    std::cout << "Enter Book ID: ";
    is >> id;
    book.setId(id);

    std::cout << "Enter Title: ";
    is.ignore(); // Ignore newline character from previous input
    std::getline(is, title);
    book.setTitle(title);

    std::cout << "Enter Publishing Year: ";
    is >> year;
    book.setYear(year);

    std::cout << "Enter Book availability status (true/false): ";
    is >> availability;
    book.setAvailability(availability);

    std::cout << "Enter Author: ";
    is.ignore(); // Ignore newline character from previous input
    std::getline(is, author);
    book.setAuthor(author);

    std::cout << "Enter Quantity: ";
    is >> quantity;
    book.setQuantity(quantity);

    return is;
}

#endif
