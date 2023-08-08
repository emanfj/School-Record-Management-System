#ifndef STUDENT_H
#define STUDENT_H

struct Student
{
	int id;
	std::string name;
	int age;
	int grade;
	//constructor for student instance
	Student(int id, const std::string& name,int age,int grade) 
		: id(id), name(name), age(age), grade(grade) {}

	int getId() const { return id; }  //getter for id

	//method to print out student details
	void print() const
	{
		std::cout << "ID: " << id << "\nName: " << name << "\nAge: " << age << "\nGrade: " << grade;
		std::cout << std::endl;
	}

};

//operator overloading for comparison operators
bool operator<(const Student& lhs, const Student& rhs) {
	return lhs.id < rhs.id;
}

bool operator>(const Student& lhs, const Student& rhs) {
	return lhs.id > rhs.id;
}

bool operator<=(const Student& lhs, const Student& rhs) {
	return lhs.id <= rhs.id;
}

bool operator>=(const Student& lhs, const Student& rhs) {
	return lhs.id >= rhs.id;
}

bool operator==(const Student& lhs, const Student& rhs) {
	return lhs.id == rhs.id;
}

bool operator!=(const Student& lhs, const Student& rhs) {
	return lhs.id != rhs.id;
}

//operator overloading for output stream operators
std::ostream& operator<<(std::ostream& os, const Student& student) {
	os << "\nStudent ID: " << student.id << "\nName: " << student.name << "\nAge: " << student.age << "\nGrade: " << student.grade << std::endl;
	return os;
}


#endif