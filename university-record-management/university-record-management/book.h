// TEMPLATE FOR BOOK DATA
#ifndef BOOK_H
#define BOOK_H

struct Book
{
    int id;
    std::string title;
    std::string author;
    int publishing_year;
    bool isAvailable;
    // constructor for book instance
    Book(int id, const std::string &title, const std::string &author, int year, bool isAvailable)
        : id(id), title(title), author(author), publishing_year(year), isAvailable(isAvailable) {}
    int getId() const { return id; } // getter for id

    // for printing book details
    void print() const
    {
        std::cout << "Book ID: " << id << "\nTitle: " << title << "\nPublishing Year: " << publishing_year << "\nBook availability status: " << isAvailable << "\nAuthor(s): " << author;
        std::cout << std::endl;
    }
};

// operator overloading for comparison operators
bool operator<(const Book &lhs, const Book &rhs)
{
    return lhs.id < rhs.id;
}

bool operator>(const Book &lhs, const Book &rhs)
{
    return lhs.id > rhs.id;
}

bool operator<=(const Book &lhs, const Book &rhs)
{
    return lhs.id <= rhs.id;
}

bool operator>=(const Book &lhs, const Book &rhs)
{
    return lhs.id >= rhs.id;
}

bool operator==(const Book &lhs, const Book &rhs)
{
    return lhs.id == rhs.id;
}

bool operator!=(const Book &lhs, const Book &rhs)
{
    return lhs.id != rhs.id;
}

// operator overloading for output stream operator
std::ostream &operator<<(std::ostream &os, const Book &book)
{
    os << "\nBook ID: " << book.id << "\nTitle: " << book.title << "\nPublishing Year: " << book.publishing_year
       << "\nBook availability status: " << std::boolalpha << book.isAvailable << "\nAuthor: " << book.author << std::endl;
    return os;
}

#endif
