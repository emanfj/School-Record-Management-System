#ifndef BOOK_H
#define BOOK_H

struct Book {
    int id;
    std::string title;
    std::vector<std::string> authors;
    int publishing_year;
    bool isAvailable;
    //constructor for book instance
    Book(int id, const std::string& title, const std::vector<std::string>& authors, int year, bool isAvailable)
        : id(id), title(title), authors(authors), publishing_year(year), isAvailable(available) {}

    //for printing book details
    void print() const()
    {
        std::cout << "Book ID: " << id << "\nTitle: " << title << "\nPublishing Year: " <<
            publishing_year << "\nBook availability status: " << isAvailable << "\nAuthor(s): ";
        for (int i = 0; i < authors.size(); i++)
            std::cout << authors[i] << " ";
        std::cout << std::endl;
    }
};

#endif
