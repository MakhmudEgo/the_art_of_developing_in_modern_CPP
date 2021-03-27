//
// Created by Mahmud Jego on 3/26/21.
//

#include <iostream>
#include <vector>

typedef struct s_student {
	std::string firstName;
	std::string secondName;
	int day;
	int month;
	int year;
} Student;

int main()
{
	std::vector<Student> students;
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		Student newStudent;
		std::cin >> newStudent.firstName >> newStudent.secondName
		>> newStudent.day >> newStudent.month >> newStudent.year;
		students.push_back(newStudent);
	}

	std::string command;
	int index;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		std::cin >> command >> index;

		if (index > (int)students.size() || index < 1) {
			std::cout << "bad request" << std::endl;
		} else if (command == "name") {
			std::cout	<< students[index - 1].firstName << ' '
						<< students[index - 1].secondName << std::endl;
		} else if (command == "date") {
			std::cout	<< students[index - 1].day << '.'
						<< students[index - 1].month << '.'
						<< students[index - 1].year << std::endl;
		} else {
			std::cout << "bad request" << std::endl;
		}
	}
	return (0);
}
