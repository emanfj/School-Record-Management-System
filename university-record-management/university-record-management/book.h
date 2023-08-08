// TEMPLATE FOR BOOK DATA
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

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
