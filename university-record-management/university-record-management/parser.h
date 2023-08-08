#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "student.h"
#include "book.h"
#include "borrowed_book.h"

using namespace std;

// parser function to read data from students
std::vector<Student> readStudentCSV(const string &filename)
{
	// vector of students data
	std::vector<Student> students;
	ifstream file(filename);

	if (!file.is_open())
	{
		// throw runtime_error("Could not open file");
		std::cout << "Could not open file.\n";
	}
	string line, word;

	// skip the header
	if (file.good())
	{
		getline(file, line);
	}

	while (getline(file, line))
	{
		// creates a stream of lines
		istringstream s(line);

		// vector to store individual words of a line
		vector<string> words;

		while (getline(s, word, ','))
		{
			// populating the vector
			words.push_back(word);
		}

		if (words.size() < 4) // because the student csv file is expected to have at least 4 columns
			continue;

		int id = std::stoi(words[0]);
		string name = words[1];
		int age = std::stoi(words[2]);
		int grade = std::stoi(words[3]);
		students.emplace_back(id, name, age, grade);
	}

	file.close();
	return students;
}

// parser function to read data from books
std::vector<Book> readBookCSV(const string &filename)
{
	// vector that contains books data
	vector<Book> books;
	ifstream file(filename);

	if (!file.is_open())
	{
		// throw runtime_error("Could not open file");
		std::cout << "Could not open file.\n";
	}

	string line, word;

	// skip the header
	if (file.good())
	{
		getline(file, line);
	}

	while (getline(file, line))
	{
		istringstream s(line);
		vector<string> words;

		while (getline(s, word, ','))
		{
			words.push_back(word);
		}

		if (words.size() < 5)
			continue;

		int id = std::stoi(words[0]);
		string title = words[1];
		string author = words[2];
		int publishing_year = stoi(words[3]);
		bool isAvailable = words[4] == "true" ? true : false; 
		books.emplace_back(id, title, author, publishing_year, isAvailable);
	}

	file.close();
	return books;
}

// parser function to read data from borrowed books
vector<BorrowedBook> readBorrowedCSV(const string &filename)
{
	vector<BorrowedBook> borrowedBooks;
	ifstream file(filename);

	if (!file.is_open())
	{
		// throw runtime_error("Could not open file");
		std::cout << "Could not open file.\n";
	}
	string line, word;

	// skip the header
	if (file.good())
	{
		getline(file, line);
	}

	while (getline(file, line))
	{
		istringstream s(line);
		vector<string> words;

		while (std::getline(s, word, ','))
		{
			words.push_back(word);
		}

		if (words.size() < 5)
			continue;

		int id = std::stoi(words[0]);
		string title = words[1];
		string borrower = words[2];
		string issue_date = (words[3]);
		string due_date = (words[4]);
		borrowedBooks.emplace_back(id, title, borrower, issue_date, due_date);
	}

	file.close();
	return borrowedBooks;
}
