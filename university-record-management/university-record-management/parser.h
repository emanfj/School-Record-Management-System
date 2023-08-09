#ifndef PARSER_H
#define PARSER_H


#include <string>
#include <vector>
#include "student.h"
#include "book.h"
#include "borrowed_book.h"

std::vector<Student> readStudentCSV(const std::string& filename);
std::vector<Book> readBookCSV(const std::string& filename);
std::vector<BorrowedBook> readBorrowedCSV(const std::string& filename);

#endif //PARSER_H
