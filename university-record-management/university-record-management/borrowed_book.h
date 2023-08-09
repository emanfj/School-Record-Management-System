// TEMPLATE FOR BORROWED BOOKS DATA
#ifndef BORROWED_BOOK_H
#define BORROWED_BOOK_H

#include "utilities.h"

#include "AVLTree.h"
#include "Hash_Table.h"

class BorrowedBook;

//forward declarations for overloaded operators
//comparison operators
bool operator<(const BorrowedBook& lhs, const BorrowedBook& rhs);
bool operator>(const BorrowedBook& lhs, const BorrowedBook& rhs);
bool operator==(const BorrowedBook& lhs, const BorrowedBook& rhs);
bool operator!=(const BorrowedBook& lhs, const BorrowedBook& rhs);
bool operator<=(const BorrowedBook& lhs, const BorrowedBook& rhs);
bool operator>=(const BorrowedBook& lhs, const BorrowedBook& rhs);
//stream operators
std::ostream& operator<<(std::ostream& os, const BorrowedBook& book);
std::istream& operator>>(std::istream& is, BorrowedBook& book);

//class declaration
class BorrowedBook
{
private:
    int id;
    std::string title;
    std::string borrower;
    std::string issue_date;
    std::string due_date;

public:
    // Constructor declaration
    BorrowedBook(int id, const std::string& title, const std::string& borrower, const std::string& issue_date, const std::string& due_date);

    // Getter declarations
    int getId() const;
    std::string getTitle() const;
    std::string getBorrower() const;
    std::string getIssueDate() const;
    std::string getDueDate() const;

    // Setter declarations
    void setId(int newId);
    void setTitle(const std::string& newTitle);
    void setBorrower(const std::string& newBorrower);
    void setIssueDate(const std::string& newIssueDate);
    void setDueDate(const std::string& newDueDate);

    // Method declarations
    void print() const;
    static void borrowBook(HashTable<Book>& bookInventory, HashTable<BorrowedBook>& borrowedBooks);
    static void returnBook(HashTable<Book>& bookInventory, HashTable<BorrowedBook>& borrowedBooks);
};



#endif // BORROWED_BOOK_H