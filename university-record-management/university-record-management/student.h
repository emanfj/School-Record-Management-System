// TEMPLATE FOR STUDENT DATA

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student;  // forward declaration of Student class

// operator overloading for comparison operators
bool operator<(const Student& lhs, const Student& rhs);
bool operator>(const Student& lhs, const Student& rhs);
bool operator<=(const Student& lhs, const Student& rhs);
bool operator>=(const Student& lhs, const Student& rhs);
bool operator==(const Student& lhs, const Student& rhs);
bool operator!=(const Student& lhs, const Student& rhs);

// operator overloading for output stream operator
std::ostream& operator<<(std::ostream& os, const Student& student);
// operator overloading for input stream operator
std::istream& operator>>(std::istream& is, Student& student);

class Student 
{
private:
    int id;
    std::string name;
    int age;
    int grade;

public:
    // constructor for student instance
    Student(int id, const std::string& name, int age, int grade)
        : id(id), name(name), age(age), grade(grade) {}

    // getters
    int getId() const { return id; }
    std::string getName() const { return name; }
    int getAge() const { return age; }
    int getGrade() const { return grade; }

    // setters
    void setId(int newId) { id = newId; }
    void setName(const std::string& newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }
    void setGrade(int newGrade) { grade = newGrade; }

    // method to print out student details
    void print() const {
        std::cout << "ID: " << id << "\nName: " << name << "\nAge: " << age << "\nGrade: " << grade << std::endl;
    }
    
};

// operator overloading for comparison operators
bool operator<(const Student& lhs, const Student& rhs) {
    return lhs.getName() < rhs.getName();
}

bool operator>(const Student& lhs, const Student& rhs) {
    return lhs.getName() > rhs.getName();
}

bool operator<=(const Student& lhs, const Student& rhs) {
    return lhs.getName() <= rhs.getName();
}

bool operator>=(const Student& lhs, const Student& rhs) {
    return lhs.getName() >= rhs.getName();
}

bool operator==(const Student& lhs, const Student& rhs) {
    return lhs.getName() == rhs.getName();
}

bool operator!=(const Student& lhs, const Student& rhs) {
    return lhs.getName() != rhs.getName();
}

// operator overloading for output stream operator
std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "\nStudent ID: " << student.getId() << "\nName: " << student.getName() << "\nAge: " << student.getAge() << "\nGrade: " << student.getGrade() << std::endl;
    return os;
}

// operator overloading for input stream operator
std::istream& operator>>(std::istream& is, Student& student) {
    int id;
    std::string name;
    int age;
    int grade;

    std::cout << "Enter Student ID: ";
    is >> id;
    student.setId(id);

    std::cout << "Enter Student Name: ";
    is.ignore(); // clear the newline from the buffer
    std::getline(is, name);
    student.setName(name);

    std::cout << "Enter Student Age: ";
    is >> age;
    student.setAge(age);

    std::cout << "Enter Student Grade: ";
    is >> grade;
    student.setGrade(grade);

    return is;
}
#endif
