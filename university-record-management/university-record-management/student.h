#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
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

    // method to print out student details
    void print() const {
        std::cout << "ID: " << id << "\nName: " << name << "\nAge: " << age << "\nGrade: " << grade << std::endl;
    }
};

// operator overloading for comparison operators
bool operator<(const Student& lhs, const Student& rhs) {
    return lhs.getId() < rhs.getId();
}

bool operator>(const Student& lhs, const Student& rhs) {
    return lhs.getId() > rhs.getId();
}

bool operator<=(const Student& lhs, const Student& rhs) {
    return lhs.getId() <= rhs.getId();
}

bool operator>=(const Student& lhs, const Student& rhs) {
    return lhs.getId() >= rhs.getId();
}

bool operator==(const Student& lhs, const Student& rhs) {
    return lhs.getId() == rhs.getId();
}

bool operator!=(const Student& lhs, const Student& rhs) {
    return lhs.getId() != rhs.getId();
}

// operator overloading for output stream operator
std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "\nStudent ID: " << student.getId() << "\nName: " << student.getName() << "\nAge: " << student.getAge() << "\nGrade: " << student.getGrade() << std::endl;
    return os;
}

#endif
