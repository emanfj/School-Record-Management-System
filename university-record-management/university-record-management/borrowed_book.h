#ifndef BORROWED_BOOK_H
#define BORROWED_BOOK_H

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

	//method to print out borrowed book details
	void print() const
	{
		std::cout << "ID: " << id << "\nTitle: " << title << "\nBorrowed by: " << borrower << "\nIssue Date: "
			<< issue_date << "\nDue Date:" << due_date;
		std::cout << std::endl;
	}

};

#endif