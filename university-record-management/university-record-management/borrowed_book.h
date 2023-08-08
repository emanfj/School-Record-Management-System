// TEMPLATE FOR BORROWED BOOKS DATA

#ifndef BORROWED_BOOK_H
#define BORROWED_BOOK_H

#include "utilities.h"

struct BorrowedBook
{
	int id;
	std::string title;
	std::string borrower;
	std::string issue_date;
	std::string due_date;
	//constructor for borrowed book instance
	BorrowedBook(int id, const std::string& title, const std::string borrower, const std::string& issue_date, const std::string& due_date)
		: id(id), title(title), borrower(borrower), issue_date(issue_date), due_date(due_date) {}

	//getter functions
	int getId() const { return id; }
	string getTitle() const { return title; }
	string getBorrower() const { return borrower; }
	string getIssueDate() const { return issue_date; }
	string getDueDate() const { return due_date; }

	//method to print out borrowed book details
	void print() const
	{
		std::cout << "ID: " << id << "\nTitle: " << title << "\nBorrowed by: " << borrower << "\nIssue Date: "
			<< issue_date << "\nDue Date:" << due_date;
		std::cout << std::endl;
	}

	//funtion for borrowing a book from the inventory
    void borrowBook(HashTable<Book>& bookInventory, HashTable<BorrowedBook>& borrowedBooks) {
        std::string bookTitle;

        //prompt the user for a book name
        std::cout << "Enter the name of the book you want to borrow: ";
        std::getline(std::cin, bookTitle);

        //get the AVLTree corresponding to the book title
        AVLTree<Book>* tree = bookInventory.search(bookTitle); //hash table search function

        //loop through each book in the tree if it is found
        if (tree) {
            std::vector<Book> books = tree->getValues();    //storing the vector of books (Book object)
            for (int i = 0; i < books.size(); i++)  //iterate over said vector
            { 
                Book& book = books[i];  //creating a reference to each book object at current index
                //check if this is the book user wants to borrow
                if (book.getTitle() == bookTitle && book.getAvailability() && book.getQuantity() > 0) {
                    std::cout << "The book " << bookTitle << " is available.You can borrow it.\n";

                    //reduce the quantity by one
                    book.setQuantity(book.getQuantity() - 1); 

                    //get user name
                    std::string userName;
                    std::cout << "Enter your name: ";
                    std::getline(std::cin, userName);

                    //get the dates
                    std::string issue_date = getCurrentDate();
                    std::string due_date = getTwoWeeksLaterDate();

                    //create a BorrowedBook object and add it to the hash table
                    BorrowedBook newBorrowedBook(book.getId(), book.getTitle(), userName, issue_date, due_date);
                    borrowedBooks.insert(bookTitle, newBorrowedBook);

                    return;
                }
            }
        }

        //if the book is not found in the inventory
        std::cout << "sorry! The book you requested is not available.\n";
    }

    void returnBook(HashTable<Book>& bookInventory, HashTable<BorrowedBook>& borrowedBooks) {
        std::string bookTitle;
        std::string userName;

        //prompt the user for a book name
        std::cout << "Enter the name of the book you want to return: ";
        std::getline(std::cin, bookTitle);

        //check if the book exists in the book inventory
        AVLTree<Book>* bookTree = bookInventory.search(bookTitle);
        if (!bookTree)
        {
            std::cout << "Invalid attempt.\nEntered book does not exist in borrowed books inventory.\n";
            return;
        }

        //prompt the user for their name
        std::cout << "Enter your name: ";
        std::getline(std::cin, userName);

        //search for the borrowed book in the 'borrowedBooks' hash table
        AVLTree<BorrowedBook>* borrowedBookTree = borrowedBooks.search(bookTitle);

        //loop through each borrowed book in the tree if tree is found
        if (borrowedBookTree)
        {
            std::vector<BorrowedBook> borrowedBooksVector = borrowedBookTree->getValues();
            for (int i = 0; i < borrowedBooksVector.size(); i++) {
                BorrowedBook& borrowedBook = borrowedBooksVector[i];

                // Check if this is the borrowed book that the user wants to return
                if (borrowedBook.getTitle() == bookTitle && borrowedBook.getBorrower() == userName) {
                    std::cout << "Borrowed book found. You can return it.\n";

                    //remove the returned book from the 'borrowedBooks' hash table
                    borrowedBooks.remove(bookTitle, borrowedBook);

                    // Increase the quantity of the book in the 'bookInventory' hash table
                    AVLTree<Book>* bookTree = bookInventory.search(bookTitle);

                    //loop through each book in the tree if tree is found
                    if (bookTree)
                    {
                        std::vector<Book> books = bookTree->getValues();
                        for (int j = 0; j < books.size(); j++)
                        {
                            Book& book = books[j];

                            //check if this is the book that was returned
                            if (book.getTitle() == bookTitle)
                            {
                                book.setQuantity(book.getQuantity() + 1);
                                book.updateAvailabilityStatus();
                                return;
                            }
                        }
                    }
                }
            }
        }

        //if the borrowed book is not found
        std::cout << "Sorry! The book you returned was not found in the borrowed book inventory.\n";
    }

};

#endif