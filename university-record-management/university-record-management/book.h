// TEMPLATE FOR BOOK DATA
#ifndef BOOK_H
#define BOOK_H

struct Book {
    int id;
    std::string title;
    std::string author;
    int publishing_year;
    bool isAvailable;

public:
    // constructor for book instance
    Book(int id, const std::string& title, const std::string& author, int year, bool isAvailable)
        : id(id), title(title), author(author), publishing_year(year), isAvailable(isAvailable) {}

    // getter functions
    int getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getYear() const { return publishing_year; }
    bool getAvailability() const { return isAvailable; }

    // for printing book details
    void print() const {
        std::cout << "Book ID: " << id << "\nTitle: " << title << "\nPublishing Year: " <<
            publishing_year << "\nBook availability status: " << isAvailable << "\nAuthor: " << author << std::endl;
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
        << "\nBook availability status: " << std::boolalpha << book.getAvailability() << "\nAuthor: " << book.getAuthor() << std::endl;
    return os;
}

#endif
