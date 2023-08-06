#ifndef BOOK_H
#define BOOK_H

struct Book {
    int id;
    std::string title;
    std::vector<std::string> authors;
    int publishing_year;

    //constructor for book instance
    Book(int id, const std::string& title, const std::vector<std::string>& authors, int year)
        : id(id), title(title), authors(authors), publishing_year(year) {}

    //for printing book details
    void print() const()
    {
        std::cout << "Book ID: " << id << "\nTitle: " << title << "\nPublishing Year: " << publishing_year << "\nAuthor(s): ";
        for (int i = 0; i < authors.size(); i++)
            std::cout << authors[i] << " ";
        std::cout << std::endl;
    }
};

#endif
