#ifndef BORROWED_BOOK_H
#define BORROWED_BOOK_H

struct BorrowedBook
{
	int id;
	std::string title;
	std::string issue_date;
	std::string due_date
	//constructor for book instance
	Book(int id, const std::string& title, std::string& issue_date, std::string& due_date)
		: id(id), title(title), issue_date(issue), due_date(due) {}

	//method to print out borrowed book details
	void print() const
	{
		std::cout << "ID: " << id << "\nTitle: " << title << "\nIssue Date: " 
			<< issue_date << "\nDue Date:" << due_date;
		std::cout << std::endl;
	}

};

#endif