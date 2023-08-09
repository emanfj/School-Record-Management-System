#include "student.h"

//definitions for class member methods
   // constructor for student instance
Student::Student(int id, const std::string& name, int age, int grade)
    : id(id), name(name), age(age), grade(grade) {}

// getters
int Student::getId() const { return id; }
std::string Student::getName() const { return name; }
int Student::getAge() const { return age; }
int Student::getGrade() const { return grade; }

// setters
void Student::setId(int newId) { id = newId; }
void Student::setName(const std::string& newName) { name = newName; }
void Student::setAge(int newAge) { age = newAge; }
void Student::setGrade(int newGrade) { grade = newGrade; }

// method to print out student details
void Student::print() const {
    std::cout << "ID: " << id << "\nName: " << name << "\nAge: " << age << "\nGrade: " << grade << std::endl;
}

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