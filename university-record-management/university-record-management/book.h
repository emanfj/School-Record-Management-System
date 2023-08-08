// TEMPLATE FOR BOOK DATA
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

#include "AVLTree.h"

class Book {
    int id;
    std::string title;
    std::string author;
    int publishing_year;
    bool isAvailable;
    int quantity;

public:
    // constructor for book instance
    Book(int id, const std::string& title, const std::string& author, int year, bool isAvailable, int quantity)
        : id(id), title(title), author(author), publishing_year(year), isAvailable(isAvailable), quantity(quantity) {}

    // getter functions
    int getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getYear() const { return publishing_year; }
    bool getAvailability() const { return isAvailable; }
    int getQuantity() const { return quantity; }

    //setter (helper) functions
    void setQuantity(int newQuantity) {   this->quantity = newQuantity; }
    void setAvailability(bool availability) {   this->isAvailable = availability;   }

    // for printing book details
    void print() const {
        std::cout << "Book ID: " << id << "\nTitle: " << title << "\nPublishing Year: " <<
            publishing_year << "\nBook availability status: " << isAvailable << "\nAuthor: " 
            << author << "\nQuantity: " << quantity << std::endl;
    }
    /*void print() const
    {
        //print the current instance of the class using the overloaded output stream operator
        std::cout << *this;
    }*/

    //function to switch between availability status of a book
    void updateAvailabilityStatus() 
    {
        if (getQuantity() > 0) {
            setAvailability(true);
        }
        else {
            setAvailability(false);
        }
    }

    //checks if a book is available or not
    bool isBookAvailable(HashTable<Book>& bookTable, const string& title) {
        //get the AVL tree corresponding to the title
        AVLTree<Book>* tree = bookTable.search(title);

        if (tree) 
        {
            //search for the book in the tree
            Book* book = tree->search(title);  

            if (book) 
            {
                //if the book is available check if it's available
                return getAvailability();
            }
        }

        //if the tree is not found or the book is not found in the tree
        return false; //book not found or not available
    }

    //retrieve books that are set as available
    void retrieveAndPrintAvailableBooks(HashTable<AVLTree<Book>>& bookTable) 
    {
        cout << "Available Books:" << endl;

        //get all items from the hash table
        std::vector<HashTable<AVLTree<Book>>::Item*> items = bookTable.getItems();

        //iterate through the hash table to find the available books
        for (int i = 0; i < items.size(); i++)
        {
            AVLTree<Book>* avlTree = items[i]->value; // Access the 'value' field of the Item

            if (avlTree != nullptr)
            {
                //get all books from the AVL tree
                std::vector<Book> books = avlTree->getValues();

                //loop over the books and print the ones that are available
                for (int j = 0; j < books.size(); j++)
                    if (books[j].getAvailability())
                        cout << books[j] << endl;
            }
        }

    }



};

// operator overloading for comparison operators
bool operator<(const Book& lhs, const Book& rhs) {
    return lhs.getId() < rhs.getId();
}

bool operator>(const Book& lhs, const Book& rhs) {
    return lhs.getId() > rhs.getId();
}

bool operator<=(const Book& lhs, const Book& rhs) {
    return lhs.getId() <= rhs.getId();
}

bool operator>=(const Book& lhs, const Book& rhs) {
    return lhs.getId() >= rhs.getId();
}

bool operator==(const Book& lhs, const Book& rhs) {
    return lhs.getId() == rhs.getId();
}

bool operator!=(const Book& lhs, const Book& rhs) {
    return lhs.getId() != rhs.getId();
}

// operator overloading for output stream operator
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "\nBook ID: " << book.getId() << "\nTitle: " << book.getTitle() << "\nPublishing Year: " << book.getYear()
        << "\nBook availability status: " << std::boolalpha << book.getAvailability() << "\nAuthor: " << book.getAuthor() 
        << "\nQuantity: " << book.getQuantity() << std::endl;
    return os;
}

#endif
