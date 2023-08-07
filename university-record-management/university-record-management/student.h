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
		std::cout << "ID: " << id << "\nName: " << name << "\Age: " << age << "\nGrade: " << grade;
		std::cout << std::endl;
	}

};

#endif